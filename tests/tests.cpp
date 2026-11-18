//
// Rover Expedition: tests for the logic classes.
//
// These tests never open a window, so they don't use Graphics1300.
// Build and run them from the Graphics1300 folder with:
//     build_tests.bat          (Windows)
//     bash build_tests.sh      (Mac or Linux)
// The tests run from inside the tests folder, so put any test data files
// (such as invalid world files) there.
//

#include <iostream>
#include <string>
using namespace std;

#include "../rover/Location.h"
#include "../rover/World.h"
#include "../rover/Direction.h"
#include "../rover/Mission.h"
#include "../rover/Rover.h"
#include "../rover/TextUtils.h"

int testsPassed = 0;
int testsFailed = 0;

// Prints whether one test passed and counts it.
void check(bool condition, string description) {
    if (condition) {
        cout << "PASS: " << description << endl;
        testsPassed++;
    } else {
        cout << "FAIL: " << description << endl;
        testsFailed++;
    }
}

void testLocation() {
    Location a(2, 3);
    Location b(2, 3);
    Location c(3, 2);
    check(a.equals(b), "locations with the same coordinates are equal");
    check(!a.equals(c), "locations with swapped coordinates are not equal");

    Location corner(9, 7);
    Location pastEastEdge(10, 7);
    Location pastSouthEdge(9, 8);
    check(corner.isWithinBounds(10, 8), "(9, 7) is inside a 10 x 8 grid");
    check(!pastEastEdge.isWithinBounds(10, 8), "(10, 7) is outside a 10 x 8 grid");
    check(!pastSouthEdge.isWithinBounds(10, 8), "(9, 8) is outside a 10 x 8 grid");
}

void testSplit() {
    string fields[3];
    split("FF,2,1", ',', fields, 3);
    check(fields[0] == "FF" && fields[1] == "2" && fields[2] == "1",
          "split separates three comma-separated fields");
}

int main() {
    testLocation();
    testSplit();

    // TODO: add your tests here. The project description lists the
    // tests you must include.

    cout << endl << testsPassed << " passed, " << testsFailed << " failed." << endl;
    return 0;
}
