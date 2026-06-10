// Problem Link: https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;


void addEdge(int u, int v, vector< vector<int>> &adj){ 
    adj[u].push_back(v);
    adj[v].push_back(u);
}



vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector< vector<int>> adj(n);


    for(int i=0; i<n; i++){
        adj[i].push_back(i);
    }
    for(int i=0; i<m; i++){
        addEdge(edges[i][0], edges[i][1], adj);
    }


    return adj;
} 