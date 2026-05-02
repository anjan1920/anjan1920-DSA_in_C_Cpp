#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int i, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target){
        //base case
        if(target == 0){
            //valid combi
            ans.push_back(temp);
            return;
        }
        else if(i == candidates.size()-1 && target == 0){
            //also a valid ans
            ans.push_back(temp);
        }
        else if(target < 0 || i >= candidates.size()){
            //not valid ans
            return ;
        }

        //add this element in combination
        //and not move on next element 
        //cause we take this i'th element again ,{we are allow on that}
        temp.push_back(candidates[i]);
        solve(i, candidates, ans, temp, target - candidates[i]);
        //we not add this in combi 
        //so remove it from the temp
        temp.pop_back();
        //don't include this
        solve(i + 1, candidates, ans, temp, target);
    }

    //we are allow to take one index more than one time
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, ans, temp, target);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    for (auto &comb : result) {
        cout << "[ ";
        for (int x : comb) {
            cout << x << " ";
        }
        cout << "]\n";
    }
        /* Time Complexity (Combination Sum):

        This is a backtracking problem where elements can be reused
        multiple times to form valid combinations.

        At each recursive call, the work done is O(1).

        From a given index i, we have two choices:
        1) take the current element again (i stays the same)
        2) skip the current element and move to the next index (i + 1)

        Since elements can be reused, the recursion depth is not fixed
        by the number of elements. Instead, it depends on the target value.

        In the worst case, the smallest element (min_ele) is repeatedly chosen.
        Therefore, the maximum depth of the recursion tree is approximately:
        T / min_ele, where T is the target value.
        
        In the worst case, the number of recursive calls grows exponentially
        with respect to the target value.

        Time Complexity: Exponential (approximately O(n^(T / min_ele)))

        Space Complexity:
        O(T / min_ele) due to recursion depth and temporary combination storage.
        */



    return 0;
}
