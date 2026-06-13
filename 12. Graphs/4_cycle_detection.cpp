// Problem Link: https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=SUBMISSION

// Undirected Graph
#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adjList)
{

    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] && neighbour != parent[front])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int src, int parent,
                 unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adjList)
{

    visited[src] = true;

    for (auto neighbour : adjList[src])
    {

        if (!visited[neighbour])
        {
            if (isCyclicDFS(neighbour, src, visited, adjList))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }

    return false;
}

void prepareAdjList(unordered_map<int, list<int>> &adjList,
                    vector<vector<int>> &edges, int n, int m)
{

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges, n, m);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            /*if (isCyclicBFS(i, visited, adjList)) {
                return "Yes";
            }*/
            if (isCyclicDFS(i, -1, visited, adjList))
            {
                return "Yes";
            }
        }
    }

    return "No";
}

// Problem Link: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0

// Directed Graph
void prepareAdjList(int n, vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }
}

bool checkCycle(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            if (checkCycle(neighbour, adjList, visited, dfsVisited))
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    prepareAdjList(n, edges, adjList);

    for (int i = 0; i < n; i++)
    {
        if (checkCycle(i, adjList, visited, dfsVisited))
        {
            return 1;
        }
    }
    return 0;
}



// Problem Link: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0

// Directed Graph using BFS

