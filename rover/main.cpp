//
// Rover Expedition: starter main program.
//
// Build and run from the Graphics1300 folder with:
//     build.bat rover          (Windows)
//     bash build.sh rover      (Mac or Linux)
// The program runs from inside the rover folder, so it finds world.txt and
// missions.txt there.
//

#include <iostream>
using namespace std;

#include "graphics/Window.h"
#include "graphics/Color.h"

#include "Location.h"
#include "World.h"
#include "Direction.h"
#include "Mission.h"
#include "Rover.h"
#include "WorldView.h"

int main() {
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 600;

    // TODO: load the world from world.txt.
    World mars;

    Location startingLocation{0, 0};
    Rover rover(mars, startingLocation, Direction::EAST, 40);

    // TODO: load the missions from missions.txt.

    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, "Rover Expedition");
    WorldView view(mars, rover);

    while (window.isOpen()) {
        // 1. Update: read input and change the program's state.
        if (window.wasKeyPressed(Key::Escape)) {
            window.close();
        }

        // 2. Clear, 3. draw, 4. show.
        window.clear(Color::Black);
        view.draw(window);
        window.update();
    }

    return 0;
}
