#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int numCities;
int minTSPGoal = INT_MAX;
vector<vector<int>> distMatrix;
vector<bool> visited;

/**
 * Recursive function to find the minimum weight Hamiltonian cycle.
 * @param currCity Current city index in exploration.
 * @param count Number of cities visited so far.
 * @param cost Cumulative weight/cost of the path.
 * @param startCity The designated root/starting city.
 */
void solveTSP(int currCity, int count, int cost, int startCity) {
    // Base Case: All cities visited, check if return path to start exists
    if (count == numCities && distMatrix[currCity][startCity] > 0) {
        minTSPGoal = min(minTSPGoal, cost + distMatrix[currCity][startCity]);
        return;
    }

    // Branching: Explore every unvisited adjacent city
    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && distMatrix[currCity][i] > 0) {
            
            // Optimization: Prune branch if current cost already exceeds best cost found
            if (cost + distMatrix[currCity][i] >= minTSPGoal) {
                continue;
            }

            visited[i] = true;
            solveTSP(i, count + 1, cost + distMatrix[currCity][i], startCity);
            
            // Backtracking step
            visited[i] = false;
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> numCities;

    distMatrix.assign(numCities, vector<int>(numCities));
    visited.assign(numCities, false);

    cout << "Enter the cost adjacency matrix (" << numCities << "x" << numCities << "):" << endl;
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> distMatrix[i][j];
        }
    }

    // Mark the starting city (City 0) as visited
    visited[0] = true;

    // Run the TSP calculation from city 0
    solveTSP(0, 1, 0, 0);

    cout << "\n--- Execution Result ---" << endl;
    if (minTSPGoal == INT_MAX) {
        cout << "No valid Hamiltonian cycle exists in the given graph." << endl;
    } else {
        cout << "Minimum Traveling Salesman Route Cost: " << minTSPGoal << endl;
    }

    return 0;
}