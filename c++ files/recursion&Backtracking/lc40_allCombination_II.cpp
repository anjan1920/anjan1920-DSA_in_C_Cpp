#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int>& candidates, set<vector<int>>& ans,
               vector<int>& temp, int target) {

        if (target == 0) {
            ans.insert(temp);
            return;
        }

        if (target < 0 || i >= candidates.size()) return;

        // pick
        temp.push_back(candidates[i]);
        solve(i + 1, candidates, ans, temp, target - candidates[i]);
        temp.pop_back();

        // non-pick
        solve(i + 1, candidates, ans, temp, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//sort the list O(nlogn)

        set<vector<int>> ans;//store the unique combination O(logn) 
        vector<int> temp;

        solve(0, candidates, ans, temp, target);

        return vector<vector<int>>(ans.begin(), ans.end());//return sorted order
        //over all time complexity 
        //Subset generation O(2^n)
        //set Insertion cost O(log K) comparisons,
        //K = number of elements currently in the set In worst case, K ≈ 2^n
        //O(2^n * log(2^n))
        //Space complexity store all combi = O(2^n) size and each have n size worst
        //= O(n2^n)
    }
};

class Solution1 {
public:
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        
        //base case
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        //loop for curr index to end
        for (int i = ind; i < arr.size(); i++) {
            //if current element is the prev once
            //and i>ind i.e current index is step ahead of prev level rec index
            //so do not take this element cause its create duplicate
            //but prev rec level have the same element but i = idx so pick it cause the indx is taken first time
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;//no need to o further target will not be zero 

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }

        // Time Complexity:
        // The recursion explores all possible subsets, which is O(2^n).
        // For each valid combination, we copy the current sequence into the answer ans.push,
        // which takes O(n) time in the worst case.
        // Therefore, overall time complexity is O(2^n * n).

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //check the notes 
        //sort to arrange the duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};


int main(){
    vector<int>candidates = {10,1,2,7,6,1,5};
        Solution* ob1 = new Solution();
        vector<vector<int>>ans = ob1->combinationSum2(candidates,4);
        //print
        for(int i = 0 ;i<ans.size();i++){
            for(int j = 0 ;j<ans[0].size();j++){
                cout<<ans[i][j]<<",";
            }
            cout<<endl;
        }

        return 0;
}