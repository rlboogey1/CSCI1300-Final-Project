//
// Helper functions for working with text read from files.
// From the recitation version of the rover.
//

#include "TextUtils.h"

void split(string line, char delimiter, string fields[], int capacity) {
    if (capacity <= 0) {
        return;
    }

    int count = 0;
    string field;
    for (char character : line) {
        if (character == delimiter) {
            if (count >= capacity) {
                return;
            }
            fields[count++] = field;
            field = "";
        } else {
            field += character;
        }
    }

    if (count >= capacity) {
        return;
    }
    fields[count++] = field;
}
