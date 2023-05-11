#include <iostream>
using namespace std;

// Display the current state of the Tic Tac Toe board
void displayBoard(char board[][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if the given player has won the game
bool checkWin(char board[][3], char player) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    // Initialize the board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Start the game
    char currentPlayer = 'X';
    int numMoves = 0;
    while (numMoves < 9) {
        // Display the board
        cout << "Current board:" << endl;
        displayBoard(board);

        // Ask for the current player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;
        numMoves++;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            displayBoard(board);
            return 0;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }

    // If there are no more moves left, the game is a tie
    cout << "Tie game!" << endl;
    displayBoard(board);
    return 0;
}
