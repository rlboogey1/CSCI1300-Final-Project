#!/usr/bin/env bash
# Builds and runs the rover's tests on macOS, Linux, or Git Bash on Windows.
#   Usage (from the Graphics1300 folder):  bash build_tests.sh
#
# Compiles tests/tests.cpp with every .cpp file in the rover folder EXCEPT
# main.cpp and WorldView.cpp, which use the graphics library.

FILES=(tests/tests.cpp)
for F in rover/*.cpp; do
    case "$(basename "$F")" in
        main.cpp|WorldView.cpp) ;;
        *) FILES+=("$F") ;;
    esac
done

g++ -std=c++17 -I. "${FILES[@]}" -o tests/tests || {
    echo
    echo "Build FAILED - see the errors above."
    exit 1
}

echo "Built tests/tests - running it..."
cd tests && ./tests
