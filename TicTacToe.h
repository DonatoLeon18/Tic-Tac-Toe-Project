#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    char** board;
    int size;
    char currentPlayer;

public:
    TicTacToe(int boardSize);
    ~TicTacToe();
    void displayBoard();
    char getCurrentPlayer();
    bool makeMove(int row, int col);
    bool checkWin();
    bool isBoardFull();
};

#endif  // TICTACTOE_H