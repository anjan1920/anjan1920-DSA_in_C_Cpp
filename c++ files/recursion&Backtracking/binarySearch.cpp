#include <iostream>
using namespace std;

int bs(int arr[], int s, int e, int key) {
    // Base case
    if (s > e) return -1;  // If the search range is invalid

    int mid = s + (e - s) / 2;

    // Check if key is present at mid
    if (arr[mid] == key) return mid;

    // If key is smaller, search in the left half
    if (arr[mid] > key) return bs(arr, s, mid - 1, key);

    // If key is larger, search in the right half
    return bs(arr, mid + 1, e, key);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int ans = bs(arr, 0, n - 1, key);
    cout << "Index of " << key << " is: " << ans << endl;

    return 0;
}
