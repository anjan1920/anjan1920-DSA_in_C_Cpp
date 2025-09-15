#include<iostream>
#include<vector>
using namespace std;

// vector<int> runningSum(vector<int>& nums) {
    //     //T.n =O(n^2)
    //     vector<int>ans;
    //     for(int i=0 ;i<nums.size();i++){
    //         int sum =0;
    //         for(int j=0 ;j<i+1 ;j++){
    //             sum = sum+nums[j];
    //         }
    //         ans.push_back(sum);
    //     }
    //     return ans;
        
    // }
     vector<int> runningSum(vector<int>& nums){
        //T.n =O(n)
        vector<int>ans;
        int sum = 0;
        for(int i = 0 ;i<nums.size();i++){
            sum = sum +nums[i];
            ans.push_back(sum);


        }
        return ans;
         
     }
int main(){

    vector<int> input = {1, 2, 3, 4, 5};
    input= runningSum(input);

    // Display the result
    cout << "Running Sum: ";
    for(int num : input) {
        cout << num << " ";
    }

    return 0;
}