#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &suduko, int row, int col, int value)
{
    int n = suduko[0].size();

    for (int i = 0; i < n; i++)
    {
        if (suduko[row][i] == value || suduko[i][col] == value || suduko[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &suduko)
{
    int n = suduko[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (suduko[row][col] == 0)
            {
                for (int value = 1; value <= n; value++)
                {
                    if (isSafe(suduko, row, col, value))
                    {
                        suduko[row][col] = value;
                        if (solve(suduko))
                        {
                            return true;
                        }
                        // backtracking
                        suduko[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudokoSolver(vector<vector<int>> &suduko)
{
    solve(suduko);
}

int main() {
    vector<vector<int>> sudoku = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    sudokoSolver(sudoku);

    cout << "Solved Sudoku:\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}