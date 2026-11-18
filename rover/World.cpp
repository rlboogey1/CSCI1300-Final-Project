//
// Created by William Wright on 10/28/26.
// Modified by Andy Carle for the final project.
//

// You may add, remove, or change these methods as long as you can explain why.

#include "Location.h"
#include "World.h"

World::World() {
    width = 0;
    height = 0;

    // TODO (will need a different parameter list)
}


bool World::isOutOfBounds(Location& location) {
    return !location.isWithinBounds(width, height);
}

bool World::isLocationAChargingStation(Location &location) {
    return false; // TODO
}