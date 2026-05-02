//532 leetcode
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//leetcode 532. K-diff Pairs in an Array
//The problem is to find the number of unique k-diff pairs in an array
//where a k-diff pair is defined as an integer pair (i, j) such as |nums[i] - nums[j]| = k.
//example: nums = [1, 2, 3, 4, 5], k = 2
//the k-diff pairs are (1, 3), (2, 4),  (3, 5)
//the output will be 3 as there are 3 unique pairs with difference k = 2

using namespace std;

// Brute force approach to find pairs with a given difference
int fundpairsBrute_force(vector<int>&nums,int k){
         //**brute force approach ->> sort the vector and check for every pair. T.n =O(n^2);
        sort(nums.begin(),nums.end());;
        set<pair<int,int>>mypair;//ony takes unique pair

        for( int i=0 ;i<nums.size() ;i++){

            for( int j=i+1 ; j<nums.size(); j++){
                //now check the pair diff == k or not
                int diff =nums[j]-nums[i];
                if(diff == k){
                    //then pushback the pair to a set -- set<pair<int,int>mypair;
                    mypair.insert( {nums[i],nums[j]});
                }
            }
        }

    return mypair.size();
        

}


// Binary search function to find an element in a sorted vector
int bs(vector<int>&nums,int s,int x){
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid] == x){
                return mid;
            }else if( x > nums[mid] ){
                //go right
                s = mid+1;
            }else{
                //go left
                e = mid-1;
            }
        }

        return -1;//when no found
        
}


// Approach using binary search to find pairs with a given difference
int findpairBS(vector<int>&nums,int k){
        //first we sort the vector
        //and we pick element from start(nums[i]),then we perform Bs operarion on remaining vector 
        //to find if its appropriate element i.e condition of diff pair nums[i]-nums[j] == k
        //so for nums[i] we will search for nums[i] so that condition is satisfied
        //now nums[j] = nums[i] + k
        //hence for nums[i] we will search for nums[i] + k is present or not


        set<pair<int,int>>myset;
        sort(nums.begin(),nums.end());

        for( int i=0 ;i<nums.size() ;i++ ){
            //now for each element lets check its appropriate element present or not
            
          int target= nums[i] + k;
          int start = i+1; //start from the next element cause the value we are looking for is nums[i] + k
          //and for a sorted vector the nums[i] + k will always be greater than nums[i] i.e right side of the vector
        
          int flag = bs(nums, start, target);
            
            //if flag != -1 means present
            //we will insert the pair in set only if its present
          if( flag != -1 ){
             //means  present 
              myset.insert( {nums[i],nums[i] +k } );
        
            }
        

        }
    return myset.size();
  //T.n = O(n){traverse in vector linear } * O(logn){bs} = O(nlogn);
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    int result = findpairBS(nums, k);

    cout << "Number of pairs with difference " << k << ": " << result << endl;

    return 0;
}
