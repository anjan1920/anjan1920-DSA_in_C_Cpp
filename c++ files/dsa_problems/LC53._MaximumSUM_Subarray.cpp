#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Naive approach:
        // Check all possible subarray sums using nested loops
        // Time complexity: O(n^2)
        
        /*
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                max_sum = max(sum, max_sum);
            }
        }
        return max_sum;
        */

        // Optimized approach using Kadane's Algorithm:
        // iterate through the array, maintaining a running sum of the current subarray
        // if the current sum becomes negative, reset it to 0 (start a new subarray)
        // track the maximum sum seen during the traversal.

        int max_sum = INT_MIN;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];

            // Update max_sum if curr_sum is greater
            max_sum = max(max_sum, curr_sum);

            // If current sum becomes negative, discard it and start fresh
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};
int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    Solution* obj;
    cout<<"Maximum sub array sum :"<<obj->maxSubArray(arr)<<endl;
    return 0;
}