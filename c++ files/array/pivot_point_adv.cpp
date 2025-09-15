#include <iostream>
using namespace std;

int findPivot(int arr[], int n) {
    //calculate total sum of array
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;//
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i];//become right some of i index
        if (leftSum == totalSum) {//check if right sum== left sum of i index

            return i;
        }
        leftSum += arr[i];//left some = present value of arr[i], then i++
    }

    return -1; // If no pivot point is found
}

int main() {
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivotIndex = findPivot(arr, n);

    if (pivotIndex != -1) {
        cout << "Pivot point is at index " << pivotIndex << endl;
    } else {
        cout << "No pivot point found in the array." << endl;
    }

    return 0;
}
