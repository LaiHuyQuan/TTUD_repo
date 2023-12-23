#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Function to check if it's safe to place a number at a specific position
bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check if 'num' is not present in the current row and column
    for (int x = 0; x < N; ++x) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            // Find an empty cell
            if (board[row][col] == 0) {
                // Try placing numbers 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        // Place the number if it's safe
                        board[row][col] = num;

                        // Recursively solve the rest of the puzzle
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // If placing the number didn't lead to a solution, backtrack
                        board[row][col] = 0;
                    }
                }

                // If no number can be placed at this cell, the puzzle is unsolvable
                return false;
            }
        }
    }

    // If the entire puzzle is filled, a solution is found
    return true;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N));

    // Input the partial Sudoku table
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    // Solve the Sudoku puzzle and count the number of solutions
    int solutionCount = 0;
    solveSudoku(board);

    cout << solutionCount << endl;

    return 0;
}
