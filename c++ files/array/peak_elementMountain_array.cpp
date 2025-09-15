#include<iostream>
#include<vector>
using namespace std;

int peakMountain(vector<int> &arr){
    int n= arr.size();
    int s=0,e=n-1,mid;
    int ans=-1;

    while( s<e ){
        mid =(s + e)/2;

        if( arr[mid] < arr[mid+1] ){
            // normal its in the a range so the target elemet should be in right //a range

            //go right
            s= mid+1;
        }else {
            //now the maybe mid is target or the target present in left side //b or peak range
            //go left

            e=mid;//so we fix the end to mid though the mid may be target element
        }
        //at the and all e,s stop on the position of targert elemt so we retuen e
        ans=e;
        


    }
    return ans;
 


}
int main(){

vector<int>arr={20,22,50,60,100,20,10};
int ans=peakMountain(arr);
cout<<"Index is "<<ans<<endl;





}