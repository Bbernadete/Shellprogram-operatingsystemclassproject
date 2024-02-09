// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//  main.cpp
//  Assignment1_Bernadete_Makiwa
//
//  Name: Zvikomborero Bernadete Makiwa
//  WSU ID:U757T432
//  Assignment 1
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // for system functions

std::string menuMessage() {
    std::string menuOption = R"(
    ****** Program Menu ******

    -- Enter the option number --
    
    Option | Command | Description
    -------------------------------
        1  |    dr   | To list directory contents
        2  |    cd   | Print working directory
        3  |  mkdir  | Create new directory
        4  |  echo   | Display a message
        5  |  type   | concatenate and display a content of files
        6  |   exit  | Exit program
    
    -------------------------------

    Enter your choice number:
)";
    return menuOption;
}

bool quitProgram(int input) {
    if (input == 6) {
        std::cout << " -------- Quitting program -------- " << std::endl << std::endl;
        return true;
    }
    else if (input < 1 || input > 6) { // display to user that their selection is invalid but keep the program running
        std::cout << " -------- Invalid selection -------- " << std::endl << std::endl;
        return false;
    }
    else {
        return false;
    }
}

//  Function to handle listing out directory content.
void printOutDirectoryContent() {
    std::cout << " -------- Executing dir - listing directory content -------- " << std::endl << std::endl;
    std::system("ls");
}

// Function to handle printing out working directory.
void printWorkingDirectory() {
    std::cout << " -------- Executing cd - current directory -------- " << std::endl << std::endl;
    std::system("cd");
}

// Function to handle creating a new directory named "NewDirectory"
void makeNewDirectory() {
    std::cout << " -------- Executing mkdir - current directory -------- " << std::endl << std::endl;
    std::system("mkdir NewDirectory");
}

// A helper function to display message using echo
void displayMessageHelper(std::string message) {
    std::cout << " -------- Executing echo - to display message -------- " << std::endl << std::endl;
    std::system(("echo " + message).c_str());
}

// A function to display message using echo
void performDisplayMessageOption() {
    std::cout << "Enter message to display: ";
    std::cin.ignore(); // ignoring any previous newline characters.
    std::string message;
    getline(std::cin, message); // read the entire line of input including spaces.
    // call helper method to display message
    displayMessageHelper(message);
}

// Helper function to read file name
std::string getFileName() {
    std::string filename;
    std::cin.ignore();
    getline(std::cin, filename);
    return filename;
}

// An helper function to write content to file
void writeToFile(std::string filename, std::string content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: unable to create/open file " << filename << std::endl;
    }
    else {
        file << content; // Writing content to file
        file.close(); // Close file after content is written into
    }
}

// Function to concatenate files
void concatenateFilecontents() {
    std::string file1Name;
    std::string file2Name;
    std::cout << "Enter file 1 name: ";
    file1Name = getFileName(); // Call helper function to capture user entry

    std::cout << "Enter file 2 name: ";
    file2Name = getFileName(); // Call helper function to capture user entry

    writeToFile(file1Name, "Content of file 1\n"); // write content of file 1 into 1
    writeToFile(file2Name, "Content of file 2\n"); // write content of file 2 into 2

    // Concatenate and display content of the two files
    std::string command = "type " + file1Name + " && type " + file2Name;
    std::system(command.c_str());
}



void selectCommand() {
    int selectedMenuOption;
    do {
        // Step 1: Print Menu
        std::cout << menuMessage();

        // Step 2: Capture user selection
        std::cin >> selectedMenuOption;

        // Step 3: Perform selected operation
        switch (selectedMenuOption) {
        case 1: // list out directory files
            printOutDirectoryContent();
            break;
        case 2: // print out the current directory
            printWorkingDirectory();
            break;
        case 3: // Make new directory named "NewDirectory"
            makeNewDirectory();
            break;
        case 4:
            performDisplayMessageOption(); // Display message to user
            break;
        case 5:
            concatenateFilecontents(); // Concatename content of files
            break;
        case 6:
            break;
        default:
            break;
        }

    } while (!quitProgram(selectedMenuOption)); // Quit program if program enters this condition

}

void shellCommandProgram() {
    std::cout << menuMessage();
    selectCommand();
}

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    shellCommandProgram(); 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
