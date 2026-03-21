#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Solves the 0/1 Knapsack problem.
 * @param W Maximum capacity of the knapsack.
 * @param wt Array of weights of the items.
 * @param val Array of values of the items.
 * @param n Number of items.
 * @return Maximum value that can be obtained.
 */
int knapsack(int W, int wt[], int val[], int n) {
    // DP table: rows = items, columns = capacity
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or 0 capacity
            } else if (wt[i - 1] <= w) {
                // Choice: Include the item or exclude it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // Item too heavy for current capacity
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Item Values:  60, 100, 120" << endl;
    cout << "Item Weights: 10, 20, 30" << endl;
    cout << "Knapsack Capacity: " << W << endl;

    int maxValue = knapsack(W, weights, values, n);

    cout << "------------------------------------" << endl;
    cout << "Maximum Value in Knapsack = " << maxValue << endl;

    return 0;
}