
#include <iostream>
#include <vector>
using namespace std;

// Display chessboard
void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check whether queen can be placed
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    // Check upper column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve N-Queens
bool solve(vector<vector<int>>& board, int row, int n) {

    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            board[row][col] = 1;
            cout << "\nPlacing Queen at (" << row << "," << col << "):\n";
            printBoard(board, n);
            if (solve(board, row + 1, n))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int n;

    cout << "Enter value of N: ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid N";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place first queen
    board[0][0] = 1;

    cout << "\nFirst Queen at (0,0):\n";
    printBoard(board, n);

    if (solve(board, 1, n)) {
        cout << "\nFinal Solution:\n";
        printBoard(board, n);
    }
    else {
        cout << "\nNo solution exists with first queen at (0,0).";
    }

    return 0;
}
