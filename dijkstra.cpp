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
 * Computes shortest paths from a source vertex using Dijkstra's Algorithm.
 * @param adj Adjacency list representing the weighted graph.
 * @param source Starting vertex.
 * @param V Number of vertices.
 */
void dijkstra(const vector<vector<Edge>>& adj, int source, int V) {
    // Vector to store the minimum distance to each vertex
    vector<int> dist(V, INT_MAX);
    
    // Min-Priority Queue tracking pairs of (distance, vertex)
    // STL priority_queue is a max-heap by default, so we use greater<> to make it a min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize source vertex
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If a shorter path to u has already been processed, skip it
        if (d > dist[u]) continue;

        // Traverse all adjacent vertices of u
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the computed shortest distances
    cout << "\n--- Shortest Distances from Source " << source << " ---\n";
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
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
        adj[v].push_back({u, w}); // Assuming an Undirected Graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(adj, source, V);

    return 0;
}