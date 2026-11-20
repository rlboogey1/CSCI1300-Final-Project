//
// Created by William Wright on 10/28/26.
//
#include <iostream>

using namespace std;

#include "Location.h"
#include "Direction.h"
#include "Mission.h"
#include "World.h"
#include "Rover.h"

string Rover::directionToString(Direction direction) {   //turns direction into a string 
    switch (direction) {
        case Direction::NORTH: return "NORTH";
        case Direction::EAST: return "EAST";
        case Direction::SOUTH: return "SOUTH";
        case Direction::WEST: return "WEST";
    }
    return "UNKNOWN";
}

Rover::Rover(World& mars, Location initialLocation, Direction initialHeading, int initialBatteryLevel) {
    world = mars;
    location = initialLocation;
    heading = initialHeading;
    batteryLevel = initialBatteryLevel; 
} //rover parameterized constructor

void Rover::setPosition(Location next) {
    location = next;
} //set rover position to the next

bool Rover::turnLeft() { //turn left function
    if (batteryLevel < TURN_COST) // returns false if there is no more battery
        return false;
    switch (heading) {
        case Direction::NORTH: heading = Direction::WEST; 
            break;
        case Direction::EAST: heading = Direction::NORTH;
            break;
        case Direction::SOUTH: heading = Direction::EAST;
            break;
        case Direction::WEST: heading = Direction::SOUTH;
            break;
    }
    batteryLevel -= TURN_COST;
    return true;
}

bool Rover::turnRight() {
    if (batteryLevel < TURN_COST) // returns false if there is no more battery
        return false;
    switch (heading) {
        case Direction::NORTH: heading = Direction::EAST;
            break;
        case Direction::EAST: heading = Direction::SOUTH;
            break;
        case Direction::SOUTH: heading = Direction::WEST;
            break;
        case Direction::WEST: heading = Direction::NORTH;
            break;
    }
    batteryLevel -= TURN_COST;
    return true;
}

bool Rover::scan() {
    if (batteryLevel < SCAN_COST) // scan area function
        return false;
    batteryLevel -= SCAN_COST;
    return true;
}

bool Rover::isAtLocation(Location& position) { // checks if rover is at a given position
    return location.equals(position);
}

bool Rover::charge() { // checks if rover is at charging station. If not returns false
    if (world.isLocationAChargingStation(location)) {
        batteryLevel = FULL_CHARGE;
        return true;
    }
    return false;
}

string Rover::toString() { // returns current status
    return "coordinates: " + location.toString()
           + ", Heading: " + directionToString(heading)
           + ", Battery: " + to_string(batteryLevel);
}

bool Rover::goForward() { // move forward function
    if (batteryLevel < MOVE_COST) {
        return false;
    }
    Location nextPossibleLocation = location;
    switch (heading) {
        case Direction::NORTH: nextPossibleLocation.decY();   // y increases to the south
            break;
        case Direction::SOUTH: nextPossibleLocation.incY();
            break;
        case Direction::EAST: nextPossibleLocation.incX();
            break;
        case Direction::WEST: nextPossibleLocation.decX();
            break;
    }

    if (world.isOutOfBounds(nextPossibleLocation)) {
        return false; // command failed, tried to move outside world boundaries
    }
    location = nextPossibleLocation; //replaces current location
    batteryLevel -= MOVE_COST;
    return true;
}

bool Rover::executeCommand(const char command) { //Executes command 
    bool wasSuccessful = false;
    switch (command) {
        case COMMAND_FORWARD: wasSuccessful = goForward(); break;
        case COMMAND_LEFT: wasSuccessful = turnLeft(); break;
        case COMMAND_RIGHT: wasSuccessful = turnRight(); break;
        case COMMAND_SCAN: wasSuccessful = scan(); break;
        case COMMAND_CHARGE: wasSuccessful = charge(); break;
        default:
            cout << "Command " << command << " failed. Invalid command."<< endl;
            return false;
    }
    printCommandStatus(command, wasSuccessful);
    return wasSuccessful;
}

void Rover::executeMission(Mission& mission) { //executes mission
    bool goalReached = false;
    for (char command: mission.getCommands()) {
        bool successful = executeCommand(command);
        if (successful) {
            mission.incrementSuccessfulCommandCount();
        }
        goalReached = goalReached || isAtLocation(mission.getGoal());
    }
    mission.setGoalReached(goalReached);
}

void Rover::printCommandStatus(char command, bool wasSuccessful) { //prints command status 
    cout << "Command " << command << " ";
    if (wasSuccessful) {
        cout << "succeeded. ";
    } else {
        cout << "failed. ";
    }
    cout << toString() << endl;
}
