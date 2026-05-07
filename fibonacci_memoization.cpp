#include <iostream>
using namespace std;

// Memoization array to store previously calculated values
long long memo[100];

/**
 * Calculates the nth Fibonacci number using recursion and memoization.
 */
long long fibonacci(int n) {
    // Base Case
    if (n <= 1) {
        return n;
    }

    // Check if the value is already in the memo table
    if (memo[n] != -1) {
        return memo[n];
    }

    // Recursive step with memoization (storing the result)
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int terms;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> terms;

    // Initialize memo table with -1 (indicating uncalculated)
    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }

    if (terms <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        cout << "Fibonacci Series: ";
        for (int i = 0; i < terms; i++) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }
    return 0;
}