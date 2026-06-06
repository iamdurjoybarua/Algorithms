#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge (target_vertex, weight)
struct Edge {
    int to;
    int weight;
};

/**
 * Finds and prints the Minimum Spanning Tree (MST) using Prim's Algorithm.
 * @param adj Adjacency list representing the graph.
 * @param V Number of vertices.
 */
void primMST(const vector<vector<Edge>>& adj, int V) {
    vector<int> key(V, INT_MAX);      // Key values used to pick minimum weight edge
    vector<int> parent(V, -1);       // Array to store constructed MST structure
    vector<bool> inMST(V, false);    // True if vertex is included in MST

    // Min-Priority Queue tracking pairs of (key_value, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with vertex 0
    key[0] = 0;
    pq.push({0, 0});

    int mstTotalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // If the vertex is already part of MST, skip processing
        if (inMST[u]) continue;

        // Include vertex in MST
        inMST[u] = true;
        mstTotalWeight += key[u];

        // Traverse all adjacent vertices of u
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print the constructed MST edges and total weight
    cout << "\n--- Minimum Spanning Tree Edges ---\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    }
    cout << "-----------------------------------\n";
    cout << "Total Minimum Spanning Tree Weight: " << mstTotalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> adj(V);

    cout << "Enter edges in format (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected Graph boundary
    }

    primMST(adj, V);

    return 0;
}