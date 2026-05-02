#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) / 2;
    
    // Calculating the length of left and right temp arrays
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;
    
    // Dynamically allocate arrays on the heap
    int* left = new int[lenLeft];
    int* right = new int[lenRight];

    // Copy the values from the main array to left
    int k = s; // Starting of the left array
    for (int i = 0; i < lenLeft; i++) {
        left[i] = arr[k];
        k++;
    }

    // Copy the values from the main array to the right temp array
    k = mid + 1; // Starting of the right array
    for (int i = 0; i < lenRight; i++) {
        right[i] = arr[k];
        k++;
    }

    // Merge the two arrays in sorted order using two-pointer approach
    int left_index = 0;
    int right_index = 0;
    int mainArr_index = s;

    while (left_index < lenLeft && right_index < lenRight) {
        if (left[left_index] < right[right_index]) {
            // Insert the smaller element in the main array
            arr[mainArr_index] = left[left_index];
            mainArr_index++;
            left_index++;
        } else {
            // Insert the smaller element in the main array
            arr[mainArr_index] = right[right_index];
            mainArr_index++;
            right_index++;
        }
    }

    // If there are remaining elements in the left or right array
    if (left_index < lenLeft) {
        while (left_index < lenLeft) {
            arr[mainArr_index] = left[left_index];
            mainArr_index++;
            left_index++;
        }
    }
    if (right_index < lenRight) {
        while (right_index < lenRight) {
            arr[mainArr_index] = right[right_index];
            mainArr_index++;
            right_index++;
        }
    }

    // Deallocate the memory for temporary arrays
    delete[] left;
    delete[] right;
}

void mergeSort(vector<int>& arr, int s, int e) {
    // Base case
    if (s > e) return;
    if (s == e) return;

    int mid = (s + e) / 2;

    // Divide the left half
    mergeSort(arr, s, mid);
    // Divide the right half
    mergeSort(arr, mid + 1, e);
    // Merge them
    merge(arr, s, e);
}

vector<int> sortArray(vector<int>& nums) {
    // Applying merge sort
    int s = 0;
    int e = nums.size() - 1;
    mergeSort(nums, s, e);
    return nums;
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    vector<int> sorted_nums = sortArray(nums);

    for (int i = 0; i < sorted_nums.size(); i++) {
        cout << sorted_nums[i] << " ";
    }
    cout << endl;

    return 0;
}
