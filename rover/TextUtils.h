//
// Helper functions for working with text read from files.
// From the recitation version of the rover.
//

#ifndef CSCI1300_CS1_TEXTUTILS_H
#define CSCI1300_CS1_TEXTUTILS_H

#include <string>
using namespace std;

// Splits line at each delimiter and stores the pieces in fields, in order.
// Stops after capacity pieces. Returns nothing, so the caller cannot tell
// how many pieces the line had.
void split(string line, char delimiter, string fields[], int capacity);

#endif //CSCI1300_CS1_TEXTUTILS_H
