
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   

    vector<vector<int>> permute(vector<int>& nums) {
        // ans vector
        vector<vector<int>> ans;

        // map to track
        vector<bool>mpp(nums.size(), false);

        // temp to store the permutations
        vector<int> temp;

        solve(nums, ans, mpp, temp);
        return ans;
    }
      /*Time complexity:
        we generating all permutation so its required n! calls cause total permutation is n!
        and every time before the call we may traverse i = 0 to last O(n)
        .. so time complexity is O(N!)*O(N) = O(N*N!)
        space complexity 
        //ans vector O(n*n!) + temp O(n) + map O(n) 
        */
};


int main() {
    vector<int> nums = {1, 2, 3};

    Solution ob1;
    vector<vector<int>> allPer = ob1.permute(nums);

    for (int i = 0; i < allPer.size(); i++) {
        for (int j = 0; j < allPer[i].size(); j++) {
            cout << allPer[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}
