#include <iostream>
using namespace std;

int board[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        // check row and column
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solve()) return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard() {
    cout << "\nSudoku Solved:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    if (solve()) {
        printBoard();
    } else {
        cout << "Solution nahi mila :(\n";
    }

    return 0;
}
