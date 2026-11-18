//
// Created by William Wright on 10/28/26.
//

#include "Location.h"

Location::Location() { // default Location Constructor
    x = 0;
    y = 0;
} 

Location::Location(int xPos, int yPos) { // location parameterized constructor
    x = xPos;
    y = yPos;
}

void Location::add(Location& other) { 
    x += other.x;
    y += other.y;
} 

void Location::incX() { // increase x position
    x++;
}

void Location::decX() { // decrease x position
    x--;
}

void Location::incY() { // increase y position
    y++;
}

void Location::decY() { // decrease y position
    y--;
}

bool Location::equals( Location& other) {  //check if two objects have the same coordinates 
    return x == other.x && y == other.y; 
}

string Location::toString() {
    return "(" + to_string(x) + ", " + to_string(y) + ")"; // turns a location into a readable string
}

bool Location::isWithinBounds(int width, int height) { // checks if location is within bounds
    return x >= 0 && x < width && y >= 0 && y < height;
}

int Location::getX() { // getter that returns x 
    return x;
}

int Location::getY() { // getter than returns y
    return y;
}
