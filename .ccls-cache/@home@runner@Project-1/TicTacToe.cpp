#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(int boardSize) : size(boardSize), currentPlayer('X') {
    // Allocate memory for the board
    board = new char*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new char[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
}

TicTacToe::~TicTacToe() {
    // Deallocate memory for the board
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void TicTacToe::displayBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << " " << board[i][j] << " ";
            if (j < size - 1) {
                cout << "|";  // Vertical separator
            }
        }
        cout << endl;
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                cout << "---";
                if (j < size - 1) {
                    cout << "|";  // Vertical line separator
                }
            }
            cout << endl;
        }
    }
}

char TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != '-') {
        return false;  // Invalid move
    }

    board[row][col] = currentPlayer;
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    return true;  // Valid move
}

bool TicTacToe::checkWin() {
    // Check rows
    for (int i = 0; i < size; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < size; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }

    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == '-') {
                return false;  // There is an empty cell
                      }
            }
        }
        return true;  // All cells are filled
    }
