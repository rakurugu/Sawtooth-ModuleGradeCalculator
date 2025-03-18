#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <time.h>

const int MILLISECONDS = 100; // time-delay in milliseconds

// Functions Declarations
void drawWaveLoop(int size);
void drawSawtoothWaves();
int getGradePoint(const std::string& grade);
std::string moduleGrade(const int& mark);
void moduleGradeDisplay ();