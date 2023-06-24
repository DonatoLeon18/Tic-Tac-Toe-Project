#include "TicTacToe.h"
#include <iostream>
using namespace std;

int main() {

  TicTacToe game(3);

    int row, col;

    while (true) {
        game.displayBoard();

        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row column): ";
        cin >> row >> col;

        if (!game.makeMove(row, col)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (game.checkWin()) {
            cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
            break;
        }

        if (game.isBoardFull()) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;

  
}