//***pivot index?****
//The pivot index is the index where the 
//sum of all the numbers strictly to the left of the index is 
//equal to the sum of all the numbers strictly to the index's right.

//If the index is on the left edge of the array, 
//then the left sum is 0 because there are no elements to the left. 
//This also applies to the right edge of the array.

//Return the leftmost pivot index. If no such index exists, return -1
#include<iostream>
#include<vector>

using namespace std ;

int pivotIndex(vector<int>& nums) {

        int n=  nums.size();
  

     int mid=0;
    for ( int i=0 ;i<n ; i++ ){
        
     
        int sumR=0, sumL=0;
        // calculate sum of elements left side of mid index (0 to mid-1)
        for ( int j= 0 ; j< mid ;j ++){

            sumL=sumL+nums[j];
        }
        // // calculate sum of elements right side of mid index( mid-1 to n-1)
        
         for ( int k=mid+1; k< n ;k++){

            sumR =sumR+nums[k];
        }
        
        //check if sum of left of mid == sum of right of mid
        if( sumL == sumR){
            return mid;
        }else{
            mid++;
        }
    }






 
 

//cout<<"program end"<<endl;

return -1;
        
}



int main(){

    vector< int >nums ={ -1,-1, 1, 1, 0, 0};
     
   int ans= pivotIndex( nums );
   cout<< " pivot point index is:"<<ans<<endl;



return 0;
}

//this is a test run and this is not hamper for 