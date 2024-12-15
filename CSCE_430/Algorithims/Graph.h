#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u’s list.
    }

    void dfsTopologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (auto i : adj[v])
            if (!visited[i])
                dfsTopologicalSortUtil(i, visited, Stack);
        Stack.push(v);
    }

    void topologicalSort() {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfsTopologicalSortUtil(i, visited, Stack);

        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
    void TopoSort(int V, unordered_map<string, vector<string> > &graph, unordered_map<string, int> &ind)
{
    queue<string> q;
    vector<string> topoOrder;
    set<string> visited;
    for (auto &p : ind)
    {
        if (p.second == 0)
        {
            q.push(p.first);
        }
    }
    while (q.empty())
    {
        string node = q.front();
        visited.insert(node);
        q.pop();
        topoOrder.push_back(node);
        for (auto &n : graph[node])
        {
            ind[n]--;
            if ((ind[n] == 0) && (visited.find(n) == visited.end()))
            {
                q.push(n);
            }
        }
    }
    if (topoOrder.size() != V) {
        cout << "Cycle detected, topological sort not possible." << endl;
        return;
    }

    // Print topological order
    for (auto &node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
}
};