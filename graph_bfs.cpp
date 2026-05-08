#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Performs Breadth-First Search starting from a given source node.
 * @param adj Adjacency list representing the graph.
 * @param startNode The node to begin traversal from.
 * @param v Number of vertices.
 */
void BFS(vector<vector<int>>& adj, int startNode, int v) {
    vector<bool> visited(v, false); // Keep track of visited nodes
    queue<int> q;

    // Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Visit all unvisited neighbors
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int v = 5; // Number of vertices
    vector<vector<int>> adj(v);

    // Adding edges (Undirected Graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    // Perform BFS starting from node 0
    BFS(adj, 0, v);

    return 0;
}