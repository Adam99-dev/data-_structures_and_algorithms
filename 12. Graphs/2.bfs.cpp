#include <bits/stdc++.h>
using namespace std;

void preparedAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList)
{

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adjList[u].push_back(v);

        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, vector<int> &ans)
{

    queue<int> q;
    q.push(node);

    visited[node] = 1;

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto i : adjList[front])
        {

            if (!visited[i])
            {

                q.push(i);

                visited[i] = 1;
            }
        }
    }
}

vector<int> breadthFirstSearch(int V, int E, vector<vector<int>> &edges)

{

    unordered_map<int, list<int>> adjList;

    unordered_map<int, bool> visited;

    vector<int> ans;

    preparedAdjList(edges, adjList);

    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {
            bfs(adjList, visited, i, ans);
        }
    }

    return ans;
}