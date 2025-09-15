#include<iostream>
#include<vector>
using namespace std;
#include<map>

vector<int> find_union(vector<int>&nums1,vector<int>&nums2){
    //apply map approach
    map<int,bool>mpp;//map store key in sorted order 
    for(auto val:nums1){
        mpp[val]=true;
    }
    for(auto val:nums2){
        mpp[val]=true;
    }
    //now explore the map and extract the key
    vector<int>ans;
    for(auto it : mpp){
        ans.push_back(it.first);


    }

    return ans;
    //Time complexity = O(n)[n = max(nums1.size(),nums2.size())] //array traversal
    // + O(k){k=total unique element or total keys} //map traversal
    

    //T.n ~`O(n+k)
    //space complexity ~O(k)//vector + o(k)//map


}

int main(){

    vector<int>nums1 = {1,2,8,9,10};
    vector<int>nums2 = {0,5,6,7,8,10,11};

    //excepted ans nums [1,2,5,6,7,8,9,10,11]
    vector<int>nums = find_union(nums1,nums2);

    for(auto val: nums){
        cout<<val<<"|";
    }
    
}