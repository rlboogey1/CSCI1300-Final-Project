//
// Created by William Wright on 10/28/26.
// Modified by Andy Carle for the final project.
//

#ifndef CSCI1300_CS1_WORLD_H
#define CSCI1300_CS1_WORLD_H

#include "Location.h"

// You may add, remove, or change these methods as long as you can explain why.

class World {
    int width;
    int height;

public:
    // TODO: Use an appropriate constructor to initialize from the world.txt file.

    World();


    bool isOutOfBounds(Location& location);
    bool isLocationAChargingStation(Location &location);
    int getWidth() { return width;}
    int getHeight() { return height;}
};

#endif //CSCI1300_CS1_WORLD_H
