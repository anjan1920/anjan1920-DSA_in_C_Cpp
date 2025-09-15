// This is the follow-up to Leetcode 53: Maximum Subarray
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Helper function to print the subarray from start to end indices
void print_array(vector<int>& nums, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void print_maxsum_subarray(vector<int>& nums) {
    // Using Kadane's Algorithm to find the maximum subarray sum
    int max_sum = INT_MIN;
    int sum = 0;

    int start = 0, end = 0; // Initialize start and end indices
    int k = 0;              // Temporary start index for current subarray

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum > max_sum) {
            // Update max_sum and save current subarray bounds
            max_sum = sum;
            start = k;
            end = i;
        }

        if (sum < 0) {
            // If current sum is negative, reset it and move start index
            sum = 0;
            k = i + 1;
        }
    }

    cout << "Max subarray sum: " << max_sum << endl;
    cout << "Subarray: ";
    print_array(nums, start, end);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    print_maxsum_subarray(nums);
    return 0;
}
