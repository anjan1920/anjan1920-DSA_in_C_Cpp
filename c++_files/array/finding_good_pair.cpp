// Given an array of integers nums, 
// return the number of good pairs.
// A pair (i, j) is called good 
// if nums[i] == nums[j] and i < j.


#include<iostream>
using namespace std;

//finding good pair
void findGood_pair(int nums[],int n){
     int count=0;
        
        
        for(int i=0 ;i<n ;i++){

            for(int j=i ;j<n  ;j++){

                if(nums[i]==nums[j] && i<j ){//condition
                    count++;

                }
            }
        }

        cout<< count;

}

int main(){
int arr []={5,0,1,2,2};
    int count=0;
    int n=5;
    findGood_pair(arr,n);
     

        
    }