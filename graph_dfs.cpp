#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency list

    void DFSUtil(int v, vector<bool>& visited) {
        // Mark current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // For undirected graph
    }

    void DFS(int startNode) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << startNode << ": ";
        DFSUtil(startNode, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.DFS(0);

    return 0;
}