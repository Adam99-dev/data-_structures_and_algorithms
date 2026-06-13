#include <bits/stdc++.h>
using namespace std;
// Problem Link: https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM


// Kahn's Algorithm (BFS)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    // create adjacent list
    for(int i=0  ; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // stores indegree of all elements
    vector<int> inDegree(v);

    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }

    // stores 0 indegree element
    queue<int> q;

    for(int i=0 ; i<v ; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    
    vector<int> ans;

    // bfs
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i: adjList[front]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }

    return ans;
}



// DFS
void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList, int e){
    for(int i=0 ; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
}

void sortingHelper(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int,list<int>> &adjList){
    visited[node] = 1;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            sortingHelper(neighbour, visited, s, adjList);
        }
    }

    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(edges, adjList, e);

    stack<int> s;

    vector<int> ans;

    for(int i=0 ; i<v ; i++){
        if(!visited[i]){
            sortingHelper(i, visited, s, adjList);
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}