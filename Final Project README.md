# Rover Expedition Starter Code

This is the starting point for the final project. It is the multi-file rover from recitation, packaged together with the Graphics1300 library so that it is ready to build. Read the project description before you start.

## What's in this folder

| File or folder | What it is |
| :---- | :---- |
| `rover/` | Your program. Every `.cpp` file in this folder is compiled into it. |
| `rover/Location`, `World`, `Rover`, `Mission`, `Direction.h` | The classes from recitation. |
| `rover/TextUtils` | The `split` function from recitation. |
| `rover/WorldView` | The class that draws everything, including converting between cells and pixels. Its constructor stores references to `main`'s `World` and `Rover` using a member initializer list. Right now it draws a placeholder triangle that wanders around the window. |
| `rover/main.cpp` | Opens the window and runs the game loop. |
| `rover/world.txt`, `rover/missions.txt` | The example data files from the project description. |
| `tests/tests.cpp` | Your test program. It has a few example tests to show the pattern. |
| `build_tests.bat`, `build_tests.sh` | Build and run the tests. |
| Everything else | The Graphics1300 library and its examples. Its `README.md` and `API.md` explain how to use it. |

## Setting up

Unzip the starter code and open a terminal in the unzipped folder, the one that contains `build.bat`. Run every command below from that folder.

**To build and run the program:**

```
build.bat rover          (Windows; in PowerShell, type .\build.bat rover)
bash build.sh rover      (Mac or Linux)
```

The program runs from inside the `rover` folder, so it reads `world.txt` and `missions.txt` from there and writes its output files there too.

**To build and run the tests:**

```
build_tests.bat          (Windows; in PowerShell, type .\build_tests.bat)
bash build_tests.sh      (Mac or Linux)
```

The tests are compiled with every `.cpp` file in `rover/` **except** `main.cpp` and `WorldView.cpp`, and they run from inside the `tests` folder. Put any data files your tests read, such as invalid world files, in `tests/`.

## The one rule about files

Only `main.cpp` and `WorldView` may include Graphics1300 headers. `Location`, `World`, `Rover`, `Mission`, and any other logic classes you add must not. If you break this rule, your tests won't build.

## Where to start

1. Build and run the program. You should see a window with a placeholder triangle wandering around it. Press Escape to quit. Then build and run the tests.
2. **Read every file in `rover/` before you change anything.** This is code you didn't write, and several parts of it will not work for the final project as written. As you read, make a list of what will have to change and why. Your TA may ask you about this list in your interview.
3. Start on step 1 of the recommended project steps: load `world.txt` into `World`, load `missions.txt`, and run missions with console output only. Write tests as you go.
