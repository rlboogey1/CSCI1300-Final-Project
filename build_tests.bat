@echo off
rem Builds and runs the rover's tests on Windows.
rem   Usage (from the Graphics1300 folder):  build_tests.bat
rem
rem Compiles tests\tests.cpp with every .cpp file in the rover folder EXCEPT
rem main.cpp and WorldView.cpp, which use the graphics library.

setlocal EnableDelayedExpansion
set "FILES="tests\tests.cpp""
for %%F in (rover\*.cpp) do (
    if /I not "%%~nxF"=="main.cpp" if /I not "%%~nxF"=="WorldView.cpp" set "FILES=!FILES! "%%F""
)

g++ -std=c++17 -I. !FILES! -o tests\tests.exe
if errorlevel 1 goto failed

echo Built tests\tests.exe - running it...
pushd tests
.\tests.exe
popd
exit /b 0

:failed
echo.
echo Build FAILED - see the errors above.
exit /b 1
