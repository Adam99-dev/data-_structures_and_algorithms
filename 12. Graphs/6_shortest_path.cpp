/*// Problem Link: https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?interviewProblemRedirection=true&search=shortest%20path&attempt_status=COMPLETED

// Shortest path in an unweighted graph
#include <bits/stdc++.h>
using namespace std;
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges, int e)
{
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<int> shortestPathInUnweightedGraph(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adjList;
    prepareAdjList(adjList, edges, m);

    unordered_map<int, bool> visited;
    unordered_map<int, int> parentTrack;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parentTrack[s] = -1;

    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adjList[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parentTrack[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parentTrack[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

*/

// Shortest path in DAG
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back({v, weight});
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j.first << " " << j.second << ", ";
            }
            cout << endl;
        }
    }

    void dfs(int node, stack<int> &topologicalSort, unordered_map<int, bool> &visited)
    {
        visited[node] = true;

        for (auto neighbour : adjList[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, topologicalSort, visited);
            }
        }

        topologicalSort.push(node);
    }

    void getShortestPath(int src, vector<int> &distances, stack<int> &topologicalSort)
    {
        distances[src] = 0;

        while (!topologicalSort.empty())
        {
            int top = topologicalSort.top();
            topologicalSort.pop();

            if (distances[top] != INT_MAX)
            {
                for (auto neighbour : adjList[top])
                {
                    distances[neighbour.first] = min(
                        distances[neighbour.first],
                        distances[top] + neighbour.second);
                }
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(3, 4, -1);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    unordered_map<int, bool> visited;
    stack<int> topologicalSort;

    int n = 6;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, topologicalSort, visited);
        }
    }

    int src = 1;

    vector<int> distances(n, INT_MAX);

    g.getShortestPath(src, distances, topologicalSort);

    for (int i = 0; i < n; i++)
    {
        if (distances[i] == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << distances[i] << " ";
        }
    }

    return 0;
}