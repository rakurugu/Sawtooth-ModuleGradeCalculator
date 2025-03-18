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

// Functions Definitions

// This function contains the for loop needed by the drawSawtoothWaves() to draw the sawtooth waves.
void drawWaveLoop(int size)
{
    for (int i = 1; i <= size; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            std::cout << "#";
        }
        std::cout << std::endl;
        clock_t goal = MILLISECONDS + clock();
        while (goal > clock()); // introduce delay
    }
}

// This function contains User's input and loops for drawing sawtooth waves.
void drawSawtoothWaves()
{
    // Initialize our variables
    int initialSize = 0, finalSize = 0;

    // Instruct User that Inputs should be positive
    std::cout << "WELCOME TO THE SAWTOOTH WAVES PROGRAM." << std::endl;
    std::cout << "INSTRUCTION: SIZES OF WAVES MUST BE POSITIVE INTEGERS." << std::endl;
    std::cout << "**************************************************" << std::endl;


    // Get Initial Size from User
    do
    {
        std::cout << "NOTICE: Initial Size must be a Positive Integer" << std::endl;
        std::cout << "Enter the initial size of the waves: ";
        std::cin >> initialSize;

        // The code below is used to clear error state of User's input and restore the stream to a valid state.
        std::cin.clear();
        fflush(stdin);

    } while (initialSize <= 0);
    std::cout << std::endl;


    // Get final size from User
    do
    {
        std::cout << "NOTICE: Final Size must be a Positive Integer" << std::endl;
        std::cout << "Enter the final size of the waves: ";
        std::cin >> finalSize;

        // The code below is used to clear error state of User's input and restore the stream to a valid state.
        std::cin.clear();
        fflush(stdin);

    } while (finalSize <= 0);


    // Draw Sawtooth Waves
    int step = (initialSize < finalSize) ? 1 : -1;
    for (int size = initialSize; size != finalSize + step; size += step) 
    {
        drawWaveLoop(size);
    }
}
