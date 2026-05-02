//find the max size sub array of sum  = k
//array contain negative elements //can't apply sliding window


#include<vector>
#include<iostream>
using namespace std;


class Solution1 {
  public:
    int find_subArr_sumK(vector<int>&arr,int i,int k){
        int j = i;
        int sum = 0;
        int size = 0;
        while(j<arr.size()){
            sum+=arr[j];
            if(sum == k){
                //find the size 
                size =  j - i + 1;
                
                
            }
            j++;
        }
        return size;
    }
    
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int max_subArr_sumK= -1;
        int curr_subArr_sumK = 0;
        
        for(int idx = 0 ;idx<arr.size();idx++){
            curr_subArr_sumK = find_subArr_sumK(arr,idx,k);
            max_subArr_sumK = max(max_subArr_sumK,curr_subArr_sumK);
            
        }
        
        return max_subArr_sumK;
    }
};


class Solution2{
    public:
        int longestSubarray(vector<int>& arr, int k) {
            

        }

};
int main(){
    vector<int>nums = {10, 5, -10, 5, 1,10 };
    int k = 10;
    ///possible subarray = {10},{10,5,-10,5} 
    //ans = 4
    Solution1* obj;//but this takes O(n^2) time GET TLE on GFG
    int ans =  obj->longestSubarray(nums,k);
    cout<<ans<<endl;

}