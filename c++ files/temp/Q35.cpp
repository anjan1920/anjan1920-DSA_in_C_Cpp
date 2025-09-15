#include <iostream>
#include <vector>
using namespace std;
int searchInsert(std::vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    int mid, temp = 0;

    while (s <= e) {
        mid = s + (e - s) / 2;
        temp = mid;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            // Move right 
            s = mid + 1;
        } else {
            // Move left 
            e = mid - 1;
        }
    }

    // If the target is not found, determine the appropriate insertion index
    if (nums[temp] < target) return temp + 1;
    else return temp;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 3;
    int result = searchInsert(nums, target);
    cout << "The appropriate index is: " << result << endl;
    return 0;
}
