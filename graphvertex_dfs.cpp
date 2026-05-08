#include <iostream>
#include <vector>

using namespace std;

/**
 * Recursive DFS to explore reachable vertices.
 */
void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming Undirected Graph
    }

    int source, target;
    cout << "Enter source vertex to start DFS: ";
    cin >> source;
    cout << "Enter target vertex to check connectivity: ";
    cin >> target;

    vector<bool> visited(V, false);
    
    // Perform DFS from the source
    if (source >= 0 && source < V) {
        DFS(source, adj, visited);
    }

    // Results check
    cout << "\n--- Result ---" << endl;
    if (target >= 0 && target < V && visited[target]) {
        cout << "Vertex " << target << " is CONNECTED to vertex " << source << "." << endl;
    } else {
        cout << "Vertex " << target << " is NOT CONNECTED to vertex " << source << "." << endl;
    }

    return 0;
}