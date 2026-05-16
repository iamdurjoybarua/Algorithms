#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int targetSum;
int n;
vector<int> weights;
vector<int> solution;

/**
 * Backtracking function to find subsets that equal targetSum.
 * @param currentSum Sum of elements currently included in the subset.
 * @param index Index of the element being considered.
 * @param remainingSum Sum of all elements left in the set.
 */
void subsetSum(int currentSum, int index, int remainingSum) {
    // Condition 1: Solution Found
    if (currentSum == targetSum) {
        cout << "{ ";
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i] << " ";
        }
        cout << "}\n";
        return;
    }

    // Bounding Functions to Prune Branches
    if (index >= n || currentSum + remainingSum < targetSum || currentSum + weights[index] > targetSum) {
        return;
    }

    // Decision Node 1: Include weights[index]
    solution.push_back(weights[index]);
    subsetSum(currentSum + weights[index], index + 1, remainingSum - weights[index]);
    
    // Backtrack
    solution.pop_back();

    // Decision Node 2: Exclude weights[index]
    subsetSum(currentSum, index + 1, remainingSum - weights[index]);
}

int main() {
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    weights.resize(n);
    int totalSum = 0;
    cout << "Enter the positive elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        totalSum += weights[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Sorting elements enhances bounding performance
    sort(weights.begin(), weights.end());

    cout << "\n--- Valid Subsets ---" << endl;
    if (totalSum < targetSum || weights[0] > targetSum) {
        cout << "No viable subsets exist." << endl;
    } else {
        subsetSum(0, 0, totalSum);
    }

    return 0;
}