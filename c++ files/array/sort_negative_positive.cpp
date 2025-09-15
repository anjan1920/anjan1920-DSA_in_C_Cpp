#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>&nums){

    for( int i=0 ; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
void sort_NP( vector<int> &nums){


    int n= nums.size();

    int l=0,r=n-1;//initialize left = 0 and right = last index

    for (  int i=0 ;l<=r ;i++){

        if( nums[i]<0 ){//-ve 
            swap( nums[i], nums[l]);
            l++;

        }else if( nums[i]>0){
            swap( nums[i], nums[r]);
            r--;
            i--;
            //here we do i-- because we dont know what value store in nums[i], 


        }else {

        }
    }

    print(nums);
}




int main(){

    vector<int>  nums={ -2,1,5,-1,1,3,2,-8,-2,1,0,0};
    print(nums);
    sort_NP( nums);





}