//leet code 33 search in rotated sorted array
//ex sorted array --> 1,2,3,4,5
//after rotation --> say rotated at index 2 :3,4,5,1,2


//we will first find the pivot element i.e 5 here 3 , 4 , 5 (region A) 1,2(region B)
//now apply the binary search on both A & B region to find the target


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int findPivot(vector<int>& nums) {

        //first find the pivot

        int pivot = -1;

        int s = 0;
        int e  = nums.size()-1;

        while( s <= e){
            int mid = s +(e-s)/2;

            if(s == e){
                return s; 
            }else if(nums[mid+1] < nums.size() && nums[mid]>nums[mid+1]){
                //mid is the pivot here
                pivot = mid;
                return mid;
            }else if(nums[mid-1]>=0 && nums[mid-1]>nums[mid]){
                //mid-1 is the pivot
                pivot = mid -1;
                return mid-1;
            }else if(nums[s] > nums[mid]){
                //then we are i.e mid is now in B region 
                //move to left 
                e = mid -1;
            }else{
                //A region and move to right 
                s = mid+1;
            }

           
        }
        return pivot;

    }

    int bs(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }



    int search(vector<int>& nums, int target) {

            //first find the pivot index
            int piv = findPivot(nums);
            int final_ans = -1;

            if(piv == -1) {
                //no pivot
                return -1;
            }else{

                //apply binary search in A region 
                int ans1 = bs(nums,0,piv,target);
                //B region
                int ans2 = bs(nums,piv+1,nums.size()-1,target);
                final_ans = max(ans1,ans2);

                
            }

            return final_ans;



        }
       
    
};


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int  target = 0;

    Solution* obj = new Solution();
    int ans = obj->search(nums,target);
    cout<<ans<<endl;
    return 0;

    //Time complexity ~ O(log n [bs1] + log n[bs2] + log n[pivot]) ~(3log n) ~O(log n)
}