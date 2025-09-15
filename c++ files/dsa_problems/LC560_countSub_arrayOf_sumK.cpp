#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int find_subarrray_sumk(vector<int>&nums,int i,int k){
        //from index i start forming the subarray by adding one element at a a time
        int j = i;
        int count = 0;
        int sum = 0;
        
        while( j < nums.size()){
            //calculate the sum of the subarray so far
            sum+=nums[j];
            //if sum ==  k then the subarray sum == k count this subarray
            if(sum == k)count++;
            
            j++;
        }

        return count;
    }
    int subarraySum(vector<int>& nums, int k) {
        //brute force approach
        int count_subArr = 0;

        ///fro every index idx the function count the subarray of sum  == k
        //o(n)
        for(int idx = 0 ;idx<nums.size();idx++){
            int sub_arrSumk_count = find_subarrray_sumk(nums,idx,k); //o(n)
             count_subArr+= sub_arrSumk_count;//increment the subarray-sum == k  count 

        }
        return count_subArr;
        
    }
    //Total T.n = O(n^2)
};

int main(){
    vector<int>nums = {1,-1,0,2,1,-1};//expected {1,-1},{1,-1,0},{0},{1,-1} i.e outcome = 4
    int k  = 0;
    Solution* obj;
    int ans  = obj->subarraySum(nums,k);
    cout<<"Total subarray of sum:"<<k<<", is "<<ans<<endl;


}