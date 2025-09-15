#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.*/




vector<int>rearrangeArray2(vector<int>&nums){

     //Using another vectors
        //vector store the positive values 
        //T.n = O(n),Sc = O(n)+2O(n/2) ~ O(n)
        /*
        int n = nums.size();
        vector<int>posi;
        vector<int>negi;
        for(int i = 0 ;i<nums.size();i++){
            if(nums[i]<0)negi.push_back(nums[i]);
            else posi.push_back(nums[i]);
        }
        //using those two vector prepare the ans
        vector<int>ans;
        int i = 0;
        while( i <posi.size() ){
            ans.push_back(posi[i]);
            ans.push_back(negi[i]);
            i++;

        }
        return ans;
        */


    //Another appriach O(n) time complexity and O(n)space complexity
    int posiIndex = 0;
    int negIndex = 1;

    vector<int>ans(nums.size());

    for(int  i = 0 ;i<nums.size();i++){

        if(nums[i] > 0){
            //push the posiive value in ans
            ans[posiIndex] = nums[i];
            ///move the pointer to next positive place i.e 2nd next
            posiIndex+=2; //i.e 0>2>4..

        }
        else{
            ans[negIndex] = nums[i];
            negIndex+=2;
        }
    }
    return ans;
}



int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
   // rearrangeArray(nums);
   rearrangeArray2(nums);

    for(auto val : nums){
        cout<<val<<',';
    }
   
        return 0;

    

}