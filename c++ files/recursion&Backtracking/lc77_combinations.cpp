#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void solve(int n,int k ,vector<int>&number_list,
    vector<vector<int>>&ans,vector<int>&temp,int i){
        //base case 1
        if(temp.size() ==  k){
            ans.push_back(temp);  // FIXED: push temp directly
            return;
        }
        //base case 2
        //no numbers left to pick
        if(i == number_list.size()){
            return;
        }
        //base case 3
        // not enough numbers left to reach size k
        if(temp.size() + (number_list.size() - i) < k){
            return;
        }

        //we are now allow to pick a number more than one
        //first add this current elememt to our combination
        temp.push_back(number_list[i]);

        //now call recusrion to add next number
        solve(n,k,number_list,ans,temp,i+1);

        //we are back from recusrion
        //now don not take current element in combination
        //and call recusrion to add next element
        temp.pop_back();//remove the current element

        solve(n,k,number_list,ans,temp,i+1);  // FIXED: missing semicolon
    }

    vector<vector<int>> combine(int n, int k) {
        //we are allow to take the number from 1 to n 
        //and make combinatios of size 'k'
        //first make a array contain 1 to n number 
        vector<int>number_list;
        for(int i = 1 ;i<=n ;i++){
            number_list.push_back(i);
        }

        //we our task is to generate all combinations of this list of size k
        vector<vector<int>>ans;//to store final ans
        vector<int>temp;//to store a single combination

        solve(n,k,number_list,ans,temp,0);  
        //TIME COMPLEXITY:
        // We are generating all combinations of size k from n elements.
        //
        // Total combinations = nCk = n! / (k! * (n-k)!)
        //
        // For each valid combination, we copy k elements into ans.
        // So cost per combination = O(k)
        //
        // Total Time Complexity = O(nCk * k)
        //
        //
        // SPACE COMPLEXITY:
        //
        // ans Output storage: O(nCk * k)
        // Recursion stack depth 'temp' : O(k)
        // number_list array: O(n)
        //
        // Dominant space = O(nCk * k)

        return ans;
    }
};

int main(){
    Solution *obj;
    int n =4 ;
    int k =2;
    vector<vector<int>>allCombinations = obj->combine(n,k);
    //print
    for(auto vec : allCombinations){
        for(auto val : vec){
            cout<<val<<",";
        }
        cout<<endl<<"---"<<endl;
    }
    return 0;
}