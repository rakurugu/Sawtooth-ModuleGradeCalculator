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

//This function contains the if conditionals for Alphanumeric grades and it's various grade point. It's used by moduleGradeDisplay().
int getGradePoint(const std::string& grade)
{
    if (grade == "A1" || grade == "a1") return 23;
    else if (grade == "A2" || grade == "a2") return 22;
    else if (grade == "A3" || grade == "a3") return 21;
    else if (grade == "A4" || grade == "a4") return 20;
    else if (grade == "A5" || grade == "a5") return 19;
    else if (grade == "B1" || grade == "b1") return 18;
    else if (grade == "B2" || grade == "b2") return 17;
    else if (grade == "B3" || grade == "b3") return 16;
    else if (grade == "C1" || grade == "c1") return 15;
    else if (grade == "C2" || grade == "c2") return 14;
    else if (grade == "C3" || grade == "c3") return 13;
    else if (grade == "D1" || grade == "d1") return 12;
    else if (grade == "D2" || grade == "d2") return 11;
    else if (grade == "D3" || grade == "d3") return 10;
    else if (grade == "M1" || grade == "m1") return 9;
    else if (grade == "M2" || grade == "m2") return 8;
    else if (grade == "M3" || grade == "m3") return 7;
    else if (grade == "CF" || grade == "cf") return 5;
    else if (grade == "BF" || grade == "bf") return 2;
    else if (grade == "QF" || grade == "qf") return 0;
    else return -1; // Invalid grade
}

//This function contains the if conditions for User's Rounded Module Mark and it's various Alphanumeric grades. It's used by moduleGradeDisplay().
std::string moduleGrade(const int& mark)
{
    if (mark == 23) return "A1";
    else if (mark == 22) return "A2";
    else if (mark == 21) return "A3";
    else if (mark == 20) return "A4";
    else if (mark == 19) return "A5";
    else if (mark == 18) return "B1";
    else if (mark == 17) return "B2";
    else if (mark == 16) return "B3";
    else if (mark == 15) return "C1";
    else if (mark == 14) return "C2";
    else if (mark == 13) return "C3";
    else if (mark == 12) return "D1";
    else if (mark == 11) return "D2";
    else if (mark == 10) return "D3";
    else if (mark == 9) return "M1";
    else if (mark == 8) return "M2";
    else if (mark == 7) return "M3";
    else if (mark == 6) return "M3";
    else if (mark == 5) return "CF";
    else if (mark == 4) return "CF";
    else if (mark == 3) return "CF";
    else if (mark == 2) return "BF";
    else if (mark == 1) return "BF";
    else if (mark == 0) return "QF";
    else return "INVALID GRADE";
}

//This functions contain the main code for calculating the Module Grade.
void moduleGradeDisplay ()
{
    std::string grade1, grade2, grade3;                     // Initialize Variables for Alphanumeric Grade
    double weight1 = 0, weight2 = 0, weight3 = 0;           // Initialize Variables for Weighting Marks
    double finalMark1 = 0, finalMark2 = 0, finalMark3 = 0;  // Initialize Variables for Individual Assessment marks.
    double moduleMark = 0;                                 // Initialize Variable for Module Mark.
    double roundedModuleMark = 0;                          // Initialize Variable for rounding the User's Module Mark.

    std::cout << "WELCOME TO UOD MODULE GRADE PROGRAM" << std::endl;
    std::cout << "NOTICE: Assessment Grades should be Alphanumeric." << std::endl;
    std::cout << "        Weighting Marks are in Percentages." << std::endl;
    std::cout << "**************************************************" << std::endl;

    // First Assessment Inputs.
    do
    {
        std::cout << "Enter First Assessment Grade: ";
        std::getline(std::cin, grade1);
    }
    while (getGradePoint(grade1) == -1);

    do
    {
        std::cout << "Enter Weighting Mark for First Assessment: ";
        std::cin >> weight1;

        std::cin.clear();   //Used to clear error state of User's input and restore the stream to a valid state.
        fflush(stdin);
    }
    while (weight1 < 1 || weight1 >= 100);
    std::cout << std::endl;

    // Second Assessment Inputs.
    do
    {
        std::cout << "Enter Second Assessment Grade: ";
        std::getline(std::cin, grade2);
    }
    while (getGradePoint(grade2) == -1);

    do
    {
        std::cout << "Enter Weighting Mark for Second Assessment: ";
        std::cin >> weight2;

        std::cin.clear();
        fflush(stdin);
    }
    while (weight1 + weight2 >= 100 || weight2 >= 100);
    std::cout << std::endl;

    // Third Assessment Inputs. Here the third weighting mark is provided by the program.
    do
    {
        std::cout << "Enter Third Assessment Grade: ";
        std::getline(std::cin, grade3);
    }
    while (getGradePoint(grade3) == -1);

    // Calculate the third weighting mark.
    weight3 = 100 - (weight1 + weight2);
    std::cout << "This is your Third Weighting Mark: " << weight3 << std::endl;
    std::cout << std::endl;

        // Calculate Marks for each Assessment.
    finalMark1 = getGradePoint(grade1) * (weight1 / 100.00);
    finalMark2 = getGradePoint(grade2) * (weight2 / 100.00);
    finalMark3 = getGradePoint(grade3) * (weight3 / 100.00);

    std::cout << "1st assessment score is: " << finalMark1 << std::endl;
    std::cout << "2nd assessment score is: " << finalMark2 << std::endl;
    std::cout << "3rd assessment score is: " << finalMark3 << std::endl;
    std::cout << std::endl;

    // Calculate User's Module Mark
    moduleMark = finalMark1 + finalMark2 + finalMark3;
    std::cout << "Your Module Mark is: " << moduleMark << std::endl;

    // Round Module Mark to the Nearest Integer.
    roundedModuleMark = round(moduleMark);
    std::cout << "Your Rounded Module Mark is: " << roundedModuleMark << std::endl;
    std::cout << std::endl;

    // show User's Module Grade.
    std::cout << "Your Module Grade is: " << moduleGrade(roundedModuleMark) << std::endl;
}