#include<iostream>
#include<vector>
using namespace std;

//binary search
int binary_search(vector<int> &arr) {
    int n = arr.size();
    int target;
    cout << "Enter target: ";
    cin >> target;

    int s = 0, e = n - 1, mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2; // it also works with (s + e) / 2, but it may overflow when s and e are close to INT_MAX value

        // found case
        if (arr[mid] == target) {
            ans = mid;
            return ans;
        } else if (target > arr[mid]) {
            // go towards right
            s = mid + 1;
        } else if (target < arr[mid]) {
            // go towards left
            e = mid - 1;
        }
    }

    // if target not present
    return ans;
}

int main() {
    // sorted array required
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 100, 111, 112, 113, 114};
    int ans = binary_search(arr);
    
    if (ans == -1) {
        cout << "Target not present." << endl;
    } else {
        cout << "Target present at index: " << ans << endl;
    }

    return 0;
}
