//
// WorldView draws the world, the rover, and the status panel.
//

#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "graphics/Window.h"
#include "graphics/Color.h"
#include "graphics/Point.h"
#include "graphics/Triangle.h"
#include "graphics/Text.h"
#include "WorldView.h"

// The part after the colon is a member initializer list. It sets world and
// rover before the constructor body runs, which is the only way to set a
// reference member.
WorldView::WorldView(World& theWorld, Rover& theRover)
    : world(theWorld), rover(theRover) {
}

void WorldView::draw(Window& window) {
    // TODO: draw everything. Replace ALL of the code below with your own.
    //
    // PLACEHOLDER: a triangle wanders randomly around the window so you can
    // see the program is running.

    double turn = (rand() % 41 - 20) / 100.0;   // -0.20 to 0.20 radians
    demoHeading += turn;
    double speed = 120;                          // pixels per second
    demoX += cos(demoHeading) * speed * window.getDeltaTime();
    demoY += sin(demoHeading) * speed * window.getDeltaTime();

    // Bounce off the edges of the window.
    double margin = 20;
    if (demoX < margin || demoX > window.getWidth() - margin) {
        const double PI = 3.14159265358979;
        demoHeading = PI - demoHeading;
        demoX = max(margin, min(demoX, window.getWidth() - margin));
    }
    if (demoY < margin || demoY > window.getHeight() - margin) {
        demoHeading = -demoHeading;
        demoY = max(margin, min(demoY, window.getHeight() - margin));
    }

    // A triangle pointing in the direction it's heading.
    double size = 18;
    Point nose(demoX + cos(demoHeading) * size,
               demoY + sin(demoHeading) * size);
    Point backLeft(demoX + cos(demoHeading + 2.5) * size,
                   demoY + sin(demoHeading + 2.5) * size);
    Point backRight(demoX + cos(demoHeading - 2.5) * size,
                    demoY + sin(demoHeading - 2.5) * size);
    Triangle demoTriangle(nose, backLeft, backRight, Color::Orange);
    demoTriangle.draw(window);

    Text title("DEFAULT VIEW", Point(20, 20), Color::White, 3);
    title.draw(window);
    Text note("This placeholder is drawn by WorldView::draw in WorldView.cpp.",
              Point(20, 60), Color::LightGray, 1);
    note.draw(window);
    Text note2("Replace it with your own drawing of the world and the rover.",
               Point(20, 76), Color::LightGray, 1);
    note2.draw(window);

    // The rover's state, read through the reference to main's Rover.
    Text roverState("Rover " + rover.toString(), Point(20, 100), Color::LightGray, 1);
    roverState.draw(window);
}
