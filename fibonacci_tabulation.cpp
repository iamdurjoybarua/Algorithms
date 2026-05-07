#include <iostream>
#include <vector>

using namespace std;

/**
 * Calculates Fibonacci numbers using the Tabulation (Bottom-Up) approach.
 * @param n The number of terms to generate.
 */
void printFibonacciTabulation(int n) {
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }

    // Allocate memory for the table
    vector<long long> table(n);

    // Step 1: Initialize Base Cases
    table[0] = 0;
    if (n > 1) {
        table[1] = 1;
    }

    // Step 2: Fill the table iteratively (Bottom-Up)
    for (int i = 2; i < n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }

    // Step 3: Print the results
    cout << "Fibonacci Series (Tabulation): ";
    for (int i = 0; i < n; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    printFibonacciTabulation(n);

    return 0;
}