//
// Created by William Wright on 10/28/26.
//
#include <iostream>
using namespace std;

#include "Location.h"
#include "Mission.h"

Mission::Mission(string theCommands) { // Parameterized Constructor that takes the string command
    commands = theCommands;
}

bool Mission::isQuit() { // if user types "quit" 
    return commands == "quit";
}

string Mission::getStatus() { // prints the status of the code. 
    string status = "-----Mission Complete!-----\n";
    status += "Number of Successful Commands: " + to_string(numSuccessfulCommands) + "\n";
    if (goalReached) {
        status += "Goal reached!\n";
    }
    return status;
}

string Mission::getCommands() { //return commands
    return commands;
}

Location &Mission::getGoal() { // return the goal 
    return goal;
}

void Mission::setGoal(Location& newGoal) { //setting new goal
    goal = newGoal;
}

void Mission::setGoalReached(bool successOrFailure) { // set if goal is reached
    goalReached = successOrFailure;
}

void Mission::incrementSuccessfulCommandCount() { // Count Sucessful commands
    numSuccessfulCommands++;
}
