// Problem Link: https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;


void addSolution(vector<vector<int>> &chess, vector<vector<int>> &ans, int n){
	vector<int> temp;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			temp.push_back(chess[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row, int column, vector<vector<int>> &chess, int n){

    int x = row;
    int y = column;

    // Left
    while(y >= 0){
        if(chess[x][y] == 1){
            return false;
        }
        y--;
    }

    // Upper-left diagonal
    x = row;
    y = column;

    while(x >= 0 && y >= 0){
        if(chess[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    // Lower-left diagonal
    x = row;
    y = column;

    while(x < n && y >= 0){
        if(chess[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int column, vector<vector<int>> &ans, vector<vector<int>> &chess, int n){
	if(column == n){
		addSolution(chess, ans, n);
		return;
	}

	for(int row = 0 ; row < n ; row++){
		if(isSafe(row, column, chess, n)){
			chess[row][column] = 1;
			solve(column+1, ans, chess, n);

			chess[row][column] = 0;
		}
	}
}


vector<vector<int>> nQueens(int n){
	vector<vector<int>> chess (n, vector<int>(n,0));
	vector<vector<int>> ans;

	// solve(column, ans, chess, n)
	solve(0, ans, chess, n);

	return ans;
	
}