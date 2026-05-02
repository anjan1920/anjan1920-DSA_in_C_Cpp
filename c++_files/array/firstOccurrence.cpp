#include<iostream>
using namespace std;

int firstOcc(int arr[],int n , int key){
    int s = 0 , e= n-1;
    int mid;
    int ans = -1;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]== key){
            ans = mid;
            //now reduce the search space --> s to mid-1
            e = mid-1;
        }else if(arr[mid]<key){
            //go right
            s = mid+1;
        }else{
            //go left
            e = mid-1;
        }
    }
    return ans;
}
int main(){
    int arr[]={1,5,8,8,8,8,8,8,8,10,11};
    int size = 11;
    int target = 8;
    int ans= firstOcc(arr,size,target);
    if(ans == -1){
        cout<<"Key not found!!.";
    }else{
        cout<<"First occurrence of the key at index :"<<ans;
    }
    return 0;
}