/****************************************************************
File: main.cpp
Description: Tic Tac Toe game
Author: Donato Leon
Class: CSCI 120
Date: 06/26/2023
I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <iostream>
using namespace std;


class TicTacToe {
private:
    char** board;
    int size;
    char currentPlayer;

public:
    TicTacToe(int boardSize) : size(boardSize), currentPlayer('X') {
        // Allocate memory for the board
        board = new char*[size];
        for (int i = 0; i < size; i++) {
            board[i] = new char[size];
            for (int j = 0; j < size; j++) {
                board[i][j] = '-';
            }
        }
    }

    ~TicTacToe() {
        // Deallocate memory for the board
        for (int i = 0; i < size; i++) {
            delete[] board[i];
        }
        delete[] board;
    }

    void displayBoard() { 
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

    char getCurrentPlayer() {
        return currentPlayer;
    }

    bool makeMove(int row, int col) { //adds X or O to board
        if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != '-') {
            return false;  // Invalid move
        }

        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;  // Valid move
    }

    bool checkWin() {
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

    bool isBoardFull() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == '-') {
                    return false;  // There is an empty cell
                }
            }
        }
        return true;  // All cells are filled
    }
};
int main() {
const string CLEAR_SCREEN = u8"\033[2J\033[1;1H"; //clears screen

  // title and description
cout<<"                     Tic Tac Toe!"<<endl<<endl;
  cout<<"Description:"<<endl;
  cout<<"line up 3 characters in a row to win!"<<endl;
  cout<<"to enter a character, type in its grid coordinates"<<endl;
  cout<< "EX: 0 0"<<endl<<endl;

  
  TicTacToe game(3); //creates board

    int row, col; //variables for grid coordinates
  char winner;

    while (true) {
      //visual representation of grid for players
cout<<"Grid Coordinates:"<<endl;
cout<<"00 01 02"<<endl<<"10 11 12"<<endl <<"20 21 22"<<endl<<endl;
      
        game.displayBoard();

        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row column): ";
        cin >> row >> col;
      
cout<<CLEAR_SCREEN;
      
        if (!game.makeMove(row, col)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (game.checkWin()) {
          if(game.getCurrentPlayer() == 'X'){
            winner = 'O';
          } else {

            winner = 'X';
          }
            cout << "Player " << winner << " wins!" <<endl;
            break;
        }

        if (game.isBoardFull()) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;

  
}