#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int val =10;
    vector<int> searchRange(vector<int>& nums, int target) {

        int first_posi = -1;
        int last_posi = -1;

        int s = 0 ;
        int e = nums.size()-1;

        while( s <= e ){

            int mid =  s + (e-s)/2;

            if(nums[mid] == target){
                //save the index
                first_posi = mid;
                //move to find first position -->left region
                e = mid -1;


            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }

        s  = 0;
        e = nums.size()-1;
         while( s <= e ){

            int mid =  s + (e-s)/2;

            if(nums[mid] == target){
                //save the index
                last_posi = mid;
                //move to find last position -->right region
                s = mid +1;


            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return {first_posi,last_posi};

        
    }
};


int main(){

    vector<int>v = { 1,2,2,2,3,4,5,7,7,7,8,9};
    //obj
    Solution* obj = new Solution();
    vector<int>ans  = obj->searchRange(v,2);
   cout<<ans[0]<<","<<ans[1]<<endl;

    
}