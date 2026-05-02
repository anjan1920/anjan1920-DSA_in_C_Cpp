#include<iostream>
//drawback - takes too much time when n is very large;
using namespace std;

void print_arr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//rotation of array k times
void arr_rotation(int arr[], int n) {
    int k;
    cout << "Enter number of rotations: ";
    cin >> k;
    int t = k % n; // reduce number of executions

    // rotation
    while(t > 0) {
        for(int i = n - 1; i > 0; i--) {
            swap(arr[i], arr[i - 1]);
        }
        t--;
    }
    print_arr(arr, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    print_arr(arr, n);
    arr_rotation(arr, n);

    return 0;
}
