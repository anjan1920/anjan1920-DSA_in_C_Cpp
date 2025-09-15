#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int s, int e) {
    int pvt = arr[s];
    int count = 0;
    // Count how many elements are less than or equal to the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pvt) {
            count++;
        }
    }

    // Now place the pivot in the correct position
    int pvtIndex = s + count;
    swap(arr[s], arr[pvtIndex]);

    // Move the rest of the elements to the left and right partitions of the pivotIndex
    int left = s, right = e;
    while (left < pvtIndex && right > pvtIndex) {
        if (arr[left] > arr[pvtIndex] && arr[right] < arr[pvtIndex]) {
            swap(arr[left], arr[right]);
        } else if (arr[left] <= arr[pvtIndex]) {
            left++;
        } else {
            right--;
        }
    }

    return pvtIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int pivot = partition(arr, s, e);
    // Solve left part
    quickSort(arr, s, pivot - 1);
    // Solve right part
    quickSort(arr, pivot + 1, e);
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
//T.n =O(nLogn),