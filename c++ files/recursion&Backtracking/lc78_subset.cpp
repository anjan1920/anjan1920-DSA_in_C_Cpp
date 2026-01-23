#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findAll(vector<int>& temp, vector<vector<int>>& ans,vector<int>& nums, int i){
            //base case
            if (i == nums.size()) {
                ans.push_back(temp);
                return;
            }

            // pick i.e include nums[i]
            temp.push_back(nums[i]);
            //recursive  call
            findAll(temp, ans, nums, i + 1);

            //not pick
            // backtrack
            //to remove the including nums[i]
            temp.pop_back();

            //now again call recusion to make the subseq without adding current nums[i]
            findAll(temp, ans, nums, i + 1);
        }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        findAll(temp,ans,nums,0);
        return ans;
      /* Time Complexity (Subsequence / Subset Problems):

        At each recursive call, the work done is O(1).

        For every index, we have two choices:
        1) pick the element
        2) not pick the element

        This results in two recursive calls at each level.
        The index always moves forward, so the maximum depth
        of recursion is n (from i = 0 to i = n).

        The recursion tree is 
        Level 0  -> 1 call
        Level 1  -> 2 calls
        Level 2  -> 4 calls
        ...
        Level n  -> 2^n calls

        Total number of recursive calls:
        1 + 2 + 4 + ... + 2^n = O(2^n)

        Since each call does constant work,
        the overall time complexity is O(2^n).
*/

    }
};


int main(){

}