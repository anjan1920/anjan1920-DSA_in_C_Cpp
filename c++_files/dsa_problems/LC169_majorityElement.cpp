#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Hash Map Approach 
        // Time: O(n), Space: O(n)
        /*
        unordered_map<int, int> mpp;
        for (auto val : nums) {
            mpp[val]++;
        }

        int n = nums.size();
        int bound = n / 2;
        for (auto it : mpp) {
            if (it.second > bound) return it.first;
        }

        return -1; // If no majority found
        */

        //  Boyer-Moore Voting Algorithm 
        // Time: O(n), Space: O(1)
        int i = 0;
        int candi = nums[i];
        long votes = 0;

        while (i < nums.size()) {
            if (votes == 0) {
                // Need to change the candidate
                candi = nums[i];
                votes = 1;
            } else {
                if (candi == nums[i]) {
                    // Increase the votes 
                    votes++;
                } else {
                    votes--;
                }
            }
            i++;
        }

        // Now check if the current candi is majority or not
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candi) count++;

            if (count > n / 2) return candi;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = sol.majorityElement(nums);

    cout << "Majority element: " << result << endl;

    return 0;
}
