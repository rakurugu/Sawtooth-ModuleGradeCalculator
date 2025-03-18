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

int main()
{
    int choice = 0; // Initialize the choice variable.

    // A do while loop was used for the menu. This is because it ensures the menu is displayed to the User at least once.
    do
    {
        // A menu display for my program.
        std::cout << "**************************************************" << std::endl;
        std::cout << "MENU:" << std::endl;
        std::cout << "1. Draw Sawtooth Waves" << std::endl;
        std::cout << "2. Calculate Module Grade" << std::endl;
        std::cout << "3. Exit Program" << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> choice;
        std::cout << "**************************************************" << std::endl;

        // The code below is used to clear error state of User's input and restore the stream to a valid state.
        std::cin.clear();
        fflush(stdin);

        //The switch statement was used as a control flow of my Menu Display based on user's input.
        switch (choice)
        {
                case 1:
                        drawSawtoothWaves();
                        break;
                case 2:
                        moduleGradeDisplay();
                        break;
                case 3:
                        std::cout << "You Exited the Program, FAREWELL!" << std::endl;
                        break;
                default:
                        std::cout << "Invalid Entry, Enter an Integer between 1 to 3." << std::endl;
        }
    } while(choice != 3);
    

    return 0;
}