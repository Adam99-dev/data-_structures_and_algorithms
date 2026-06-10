#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);

        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;

    int m, n;
    cout << "Enter number of nodes: ";
    cin >> m;

    cout << "Enter number of edges: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();
    return 0;
};