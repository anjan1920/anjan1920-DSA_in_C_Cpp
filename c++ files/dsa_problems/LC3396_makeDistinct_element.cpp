#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;



/*
You are given an integer array nums. You need to ensure that the elements in the array are distinct.
 To achieve this, you can perform the following operation any number of times:
-Remove 3 elements from the beginning of the array.
- If the array has fewer than 3 elements, remove all remaining elements.
Note that an *empty array is considered to have distinct elements*.
- Return the minimum number of operations needed to make the elements in the array distinct.
*/

bool check_distinct(vector<int>&nums){
   unordered_set<int>mySet(nums.begin(),nums.end());
   if(mySet.size() == nums.size()) return true;
   return false;
}

int minimumOperations(vector<int>& nums) {

    //first check if is already distinct or not
    if (check_distinct(nums)) return 0; 
    if(nums.size()< 3) return {};

    
    int count  = 0;
    //else we need to remove the first 3
    while(nums.size() >= 0 ){
        count++;
        if(nums.size()<=3) return count;
        vector<int>temp(nums.begin() + 3 , nums.end());
        nums = temp;
        //now check
        if(check_distinct(nums)) return count;
       

    }
    return count;
  
}


int main(){

   vector<int>nums = {1,2,2};
   
       
    int count = minimumOperations(nums);
    cout<<count<<endl;
    return count;
            
}
 
