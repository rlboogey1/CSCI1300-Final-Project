//
// WorldView draws the world, the rover, and the status panel.
//
// WorldView and main.cpp are the ONLY files that may include Graphics1300
// headers. World, Rover, Mission, and Location must not, so that they can
// be tested without opening a window.
//

#ifndef CSCI1300_CS1_WORLDVIEW_H
#define CSCI1300_CS1_WORLDVIEW_H

#include "graphics/Window.h"
#include "Rover.h"

class WorldView {
public:
    // Remembers the world and rover that main created, so that draw()
    // always shows their current state.
    WorldView(World& theWorld, Rover& theRover);

    // Draws one frame's worth of everything. Call it between
    // window.clear() and window.update().
    void draw(Window& window);

    // TODO: draw the grid, the charging stations, the goal, revealed sample
    // sites, the rover as a triangle, its path, and the status panel.
    // TODO: convert between cells and pixels: a cell to the pixel position
    // where it is drawn, and a mouse position to the cell under it.

private:
    // References to main's World and Rover, not copies. A reference member
    // has to be set in the constructor's member initializer list (see
    // WorldView.cpp).
    World& world;
    Rover& rover;

    // ---- PLACEHOLDER: delete these when you write your own draw(). ----
    // They let the default view show a triangle wandering around the
    // window, so you can tell the program is running.
    double demoX = 450;         // center of the triangle, in pixels
    double demoY = 300;
    double demoHeading = 0.0;   // direction it faces, in radians (0 = right)
};

#endif //CSCI1300_CS1_WORLDVIEW_H
