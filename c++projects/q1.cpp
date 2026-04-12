#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v) {
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // ---------------- Modified BFS (Shortest Path) ----------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);   // To store shortest paths
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;  // Store parent to build path
                    q.push(neighbor);
                }
            }
        }
        cout << endl;

        // Print all shortest paths from source
        cout << "\nShortest Paths from " << start << ":\n";

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "Vertex " << i << ": No path\n";
                continue;
            }

            vector<int> path;
            int current = i;

            // Build path backwards using parent[]
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }

            reverse(path.begin(), path.end());

            cout << "Path to " << i << ": ";
            for (int x : path) cout << x << " ";
            cout << endl;
        }
    }

    // ---------------- DFS ----------------
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.BFS(0);
    g.DFS(0);

    return 0;
}

