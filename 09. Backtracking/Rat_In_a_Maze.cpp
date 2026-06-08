// Problem Link: https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && maze[x][y] == 1 && visited[x][y] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, string path, vector<string> &ans, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;

    // Down
    if (isSafe(x + 1, y, maze, visited, n))
    {
        solve(x + 1, y, maze, visited, path + 'D', ans, n);
    }

    // Left
    if (isSafe(x, y - 1, maze, visited, n))
    {
        solve(x, y - 1, maze, visited, path + 'L', ans, n);
    }
    // Right
    if (isSafe(x, y + 1, maze, visited, n))
    {
        solve(x, y + 1, maze, visited, path + 'R', ans, n);
    }

    // Up
    if (isSafe(x - 1, y, maze, visited, n))
    {
        solve(x - 1, y, maze, visited, path + 'U', ans, n);
    }

    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &maze, int n)
{
    vector<string> ans;

    // Edge Case
    if (maze[0][0] == 0)
    {
        return ans;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    solve(0, 0, maze, visited, "", ans, n);

    return ans;
}