#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    // Define the options for Rock, Paper, Scissors
    char options[3] = {'R', 'P', 'S'};

    // Start the game
    char playerChoice;
    while (true) {
        // Ask the player for their choice
        cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
        cin >> playerChoice;

        // Check if the player's choice is valid
        if (playerChoice != 'R' && playerChoice != 'P' && playerChoice != 'S' && playerChoice !='g') {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        // Generate the computer's choice
        char computerChoice = options[rand() % 3];

        // Display the choices
        cout << "the computer chose " << computerChoice << "." << endl;

        // Determine the winner
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl; 
        } else if (playerChoice == 'R' && computerChoice == 'S' ||
                   playerChoice == 'P' && computerChoice == 'R' ||
          playerChoice == 'g' && computerChoice == 'R'||
          playerChoice == 'g' && computerChoice == 'P'||
          playerChoice == 'g' && computerChoice == 'S'||
                   playerChoice == 'S' && computerChoice == 'P') {
            cout << "You win!" << endl;
        } else {
            cout << "The computer wins!" << endl;
        }

        // Ask the player if they want to play again
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain == 'N') {
            break;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
