#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Performs iterative Binary Search on a sorted array.
 * @param arr The sorted array to search.
 * @param size The number of elements in the array.
 * @param target The value to locate.
 * @return The index of the target, or -1 if not found.
 */
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // midpoint calculation optimized to prevent overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int data[] = {4, 12, 19, 25, 33, 47, 50, 62, 88, 95};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 33;

    cout << "Dataset: ";
    for(int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    int result = binarySearch(data, n, target);

    if (result != -1) {
        cout << "Element " << target << " identified at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the dataset." << endl;
    }

    return 0;
}