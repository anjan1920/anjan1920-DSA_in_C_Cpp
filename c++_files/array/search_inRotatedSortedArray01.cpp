#include<iostream>
#include<vector>

using namespace std;
int findPivot(vector<int>&nums ){
    int s= 0, e= nums.size()-1;
    int mid, piv=-1;
    while( s<=e ){
        
        mid = s+(e-s)/2;

        if( nums[mid] > nums[mid+1] && mid+1 < nums.size()){
            //pivot index found
            piv = mid;
            return piv;


        }else if( nums[mid] < nums[mid-1] && mid-1 >=0 ){
            // pivot at mid-1 
            piv = mid-1;
            return piv;
        }else if( nums[mid] <= nums[1]){
            //we are in right in pivot
            e = mid-1;

        }else{
            // we are in left side
             s = mid+1;
        }
    }
    return piv;
}

//binary serachi
bool binarySearch( vector<int>&arr, int target, int start, int end){
 int n= arr.size();
 int s = start, e = end;
 int mid ;
    
    bool ans=false;

    while( s<=e ){

        mid = s+ (e-s) /2;//its also work ( s+e )/2 but its over flow when s and e are close to INT_MIN value

        //found case
        if( arr[mid] == target){
            ans = mid;
            return ans;

            return ans;
        }else if( target > arr[mid] ){

            //go towwrds  right
            s= mid +1;

        }else if( target< arr[mid] ){
            //go towards left
            e = mid-1;
        }

        


    }

   //if target not present
return ans;
}


bool search_inRSArray01( vector<int>&nums , int target){
    //we first find the pivot index then appaly binary serach in both side of pivot
       int pivIndex = findPivot( nums);

     bool ans = false;
 
    if (pivIndex == -1){
        return false;
    }
    if( target <= nums[pivIndex] && target <= nums[1] ){
        //go and serach right side of piv index
        ans = binarySearch( nums,target,pivIndex+1 , nums.size()-1);

    }else{
        ans = binarySearch( nums,target,0,pivIndex);
    }
    return ans;


        
    }
    



 int main(){

    vector<int>nums ={ 2,5,6,0,0,1,2 }; // 0,0,1,2,5,6- rotated at  index -3 -> 2,5,6,0,0,1,2
    int target ;
    cout<<"Enter target:";cin>>target;

    bool ans = search_inRSArray01( nums ,target);
    cout<<ans;

 }
// n= nums.size()
//Total T.n = sortfunction( O(nlongn)) + binary( O(logn))  = O(nlogn)