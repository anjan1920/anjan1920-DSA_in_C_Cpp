//when ? --> when the array is sorted and very large  
//benefit? --> reduce the search space for the binary search 

//steps :
//First define the search space 
//then apply the binary search on that 



#include<iostream>
#include<vector>

using namespace std;



vector<int>find_searchSpace(vector<int>&nums,int target){

    int i = 0;
    if(nums[i] == target) return {i,i};

    i = 1 ;
    while( i < nums.size() && nums[i]<= target){
        i = i*2;
    }

    // at this point i cross the target just 
    //and the previous  i where the comparison performed is --> i/2 {cause i incremented by i*2}
    //i.e the start point i/2 and end is if
    return {i/2,i};

}


int bs(vector<int>&nums,int s,int e,int target){

    while( s <= e){
        int mid = s + (e-s)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]<target) s = mid +1;
        else e = mid -1;

    }

    return -1;//not found

}



int doubling_search(vector<int>&nums,int target){

    //first define search space
    vector<int>range = find_searchSpace(nums,target);

    //apply binary search on that 
    int start = range[0];
    int end = range[1];
    int target_index;
    if(start == end ){
         target_index = start;
       
    }
    else {
        target_index = bs(nums,start,end,target);
       

    }
     return target_index;

   
}


int main(){
    vector<int>nums = {1,1,1,2,3,4,5,6,8,7,9,10,11,12,13,14,14,15,15};
    int ans = doubling_search(nums,14);

    cout<<"ans :"<<ans<<endl;

    return 0;


}