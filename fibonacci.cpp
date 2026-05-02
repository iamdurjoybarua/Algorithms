#include <iostream>

using namespace std;

/**
 * Calculates the nth Fibonacci number using recursion.
 * @param n The position in the sequence.
 * @return The Fibonacci number at position n.
 */
int fibonacci(int n) {
    // Base Case: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive Step: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    cout << "Enter the number of terms for Fibonacci sequence: ";
    cin >> terms;

    if (terms <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        cout << "Fibonacci Sequence: ";
        for (int i = 0; i < terms; i++) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

    return 0;
}