# Battleship in Terminal

## Overview
This Battleship game was created during the fall semester of my freshman year on 9/15/2023. I developed it as a simple project that matched my skill level at the time, allowing me to practice coding in C++.

## Files
- **README.md:** This file provides information about the project.
- **game.cpp:** The C++ source code for the Battleship game.
- **Executable:** A compiled executable of the game. If the executable does not run on your system, you may need to compile the `game.cpp` file yourself.

## How to Use
1. **Running the Game:**
   - Open a terminal window.
   - Run the executable file directly or compile `game.cpp` if the executable is not working on your machine.

2. **Gameplay:**
   - After launching the game, you will be prompted to enter the number of ships you want to guess on a 10x10 board.
   - The ships' locations, rotations, and sizes are randomly generated within predefined parameters in the code.
   - To make a guess, enter coordinates in the format of a letter followed by a number (e.g., `A5`).
   - You have an unlimited number of guesses to find all the ships.
   - The game ends once all ship locations have been correctly guessed.

Enjoy playing Battleship in the terminal!

## Compilation Instructions
If you need to compile the game from source, follow these steps:
1. Ensure you have a C++ compiler installed (e.g., GCC).
2. Open a terminal and navigate to the directory containing `game.cpp`.
3. Compile the code using the following command:
   ```bash
   g++ game.cpp -o battleship


## Issues
- If the number of ships entered by the user is too high then ships may clip through each other.
- If there are any spaces or a letter or digit is swapped, the program will likely crash or break.
- If a non integer is entered for the number of ships the program will likely break or crash.

## Future
I will likely not revisit this program, but I know I could improve on some of the issues mentioned and add new features.
However, I think this project allowed me to exercise my new coding skills and I learned a lot while making it!
