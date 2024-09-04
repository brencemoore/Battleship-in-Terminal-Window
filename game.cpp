#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// Battleship code initialization for generation
char gridCode[10][10] = {{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                         {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}};
                    

// The code used to randomly generate ship formation
void createShip (int length, int direction, int row, int col) {
    for (int i = 0; i < length; ++i) {
        if (direction == 1) {
            if (row > length - 2) {
                gridCode[row - i][col] = 'X';
            }
             else {
                gridCode[row + i][col] = 'X';
            }
        }
        else {
            if (col > length - 2) {
                gridCode[row][col - i] = 'X';
            }
            else {
                gridCode[row][col + i] = 'X';
            }
        }
    }
}



int main() {


    // Declaring all variables used throughout code
    int row;
    int col;
    int length;
    bool loop = true;
    char response;
    int numShips;
    srand(time(0));
    string guess;
    int rowGuess;
    int colGuess;
    int xCount = 0;
    int correctGuesses = 0;
    int numGuesses = 0;
    char gridGame[10][10] = {{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}};


    // Asks how many ships will be generated
    cout << "\n\n\nHow many ships do you want: ";
    cin >> numShips;


    // Changes grid
    for (int i = 0; i < numShips; ++i) {


    // Random variables
        row = (rand() % 10);
        col = (rand() % 10);
        int direction = rand() % 2;
        length = (rand() % 4) + 2;


    // Ships are made
        if (gridCode[row][col] != 'X') {
            createShip(length, direction, row, col);
        }
        else {
            numShips += 1;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (gridCode[i][j] == 'X') {
                xCount += 1;
            }
        }
    }


    // Game loop
    while (loop == true) {


        // Prints the user's game
        cout << endl << endl << "\t X   A B C D E F G H I J" << endl << endl;
        for (int i = 0; i < 10; ++i) {
            if (i < 9) {
                cout << "\t" << " " << i + 1 << "   ";
            }
            else {
                cout << "\t" << i + 1 << "   ";
            }
            for (int j = 0; j < 10; ++j) {
                cout << gridGame[i][j] << " ";
            }
            cout << endl;
        }


        // Instructions for how to answer
        cout << "\nGuess a coordinate with a letter and\nthen a number (A1, B2, ...): ";
        cin >> guess;
        cout << endl << endl;


        // Converts answer to row and column integers
        if (islower(guess.at(0))) {
            guess.at(0) = toupper(guess.at(0));
        }
        if (guess.at(1) == 49 && guess.size() == 3) {
            rowGuess = 9;
        }
        else {
            rowGuess = guess.at(1) - 49;
        }
        colGuess = guess.at(0) - 65;


        // Checks if the guess is a hit or miss and updates user's grid
        if (gridCode[rowGuess][colGuess] == 'X') {
            gridGame[rowGuess][colGuess] = 'X';
            correctGuesses++;
        }
        else {
            gridGame[rowGuess][colGuess] = '.';
        }
        numGuesses++;
        

        // Checks if correct guesses equals amount of X's
        if (correctGuesses == xCount) {
            loop = false;
        }


        // Prints the total correct guesses
        cout << "Correct guesses: " << correctGuesses << endl;
        cout << "Number of guesses: " << numGuesses;
    }


    // Final print of the user's grid
    cout << endl << endl << "\t X   A B C D E F G H I J" << endl << endl;
    for (int i = 0; i < 10; ++i) {
        if (i < 9) {
            cout << "\t" << " " << i + 1 << "   ";
        }
        else {
            cout << "\t" << i + 1 << "   ";
        }
        for (int j = 0; j < 10; ++j) {
            cout << gridGame[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\nYou sank all the battle ships!\n\n"
         << "It took you " << numGuesses << " guesses!" << endl << endl;
    cout << "You had an accuracy of " << fixed << setprecision(2) << ((correctGuesses * (1.0)) / numGuesses) * 100.00
         << "%!" << endl << endl;

    return 0;
}