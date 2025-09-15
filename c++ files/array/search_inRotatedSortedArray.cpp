#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool search_inRSArray( vector<int>&nums , int target){

        vector<int>temp = nums;//copy all element of nums to temp array
        sort( temp.begin() ,temp.end());//sort the temp array
        // apply binary search 
        int s=0 ,e= temp.size()-1;

        bool ans = false;

        while( s<=e ){
            int mid = s + (e-s)/2;

            if( temp[mid] == target){
                ans= true;
                return ans;
            }else if( temp[mid] < target){
                //go right
                 s= mid +1;
            }else{

                e= mid-1;
            }
        }

        return ans;
        
    }
    



 int main(){

    vector<int>nums ={ 2,5,6,0,0,1,2 }; // 0,0,1,2,5,6- rotated at  index -3 -> 2,5,6,0,0,1,2
    int target ;
    cout<<"Enter target:";cin>>target;

    bool ans = search_inRSArray( nums ,target);
    cout<<ans;

 }
// n= nums.size()
//Total T.n = sort function( O(nlongn)) + binary( O(logn))  = O(nlogn)--> 
//**For O(log n) we must we  the pivot see--> LC 33**