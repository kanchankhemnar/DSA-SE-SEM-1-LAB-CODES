#include <iostream>
#include <vector>

using namespace std;

void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;    // Initialize smallest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr) {
    // Build a min heap from the input array
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapifyMin(arr, n, i);
    }
}

void heapSortMin(vector<int>& arr) {
    int n = arr.size();

    // Build a min heap
    buildMinHeap(arr);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); // Move current root to end

        // Call min heapify on the reduced heap
        heapifyMin(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform heap sort using Min Heap
    heapSortMin(arr);

    cout << "Sorted array: ";
    for (int i = n-1; i >=0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
