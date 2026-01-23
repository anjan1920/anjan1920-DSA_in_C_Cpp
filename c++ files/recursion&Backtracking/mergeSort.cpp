#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void merge_sortedArray(vector<int>&arr,int l ,int mid,int r){
        //define a temp array
        vector<int>temp;
        //pointers 
        int left = l ;
        int right = mid +1;
        while( left <= mid && right <= r){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;   
            }
        }
        //if remaining element on right or left sub array
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= r){
            temp.push_back(arr[right]);
            right++;
        }
        
        //now replace the replace the original once with this sorted once
        int i = 0;
        int j = l;
        while( j<= r){
            arr[j] = temp[i];
            j++;
            i++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        //base case
        if( l >= r){
            return ;
        }
        int mid = l +(r-l)/2;
        //divide left half
        mergeSort(arr,l,mid);
        //devide right half
        mergeSort(arr,mid+1,r);
        
        //now merge this left and right half array which are sorted now
        //i.e same as merge two sorted array
        merge_sortedArray(arr,l,mid,r);
    }
};

int main(){
    //time complexity?
    //in each level each function make 2 calls
    //the tree is like :
    /*
    level 0 : fn(n/2) fn(n/2) two function call . and work for each is O(n/2)
    so level 0 : function call 2,total work done O(n)
    level 1: function call 4 : work done is O(n)
    level 2 : function call 8 : work done O(n),
    and this level grows upto n==1 
    i.e n value changes in each level n->n/2->n/->n/8...1
    
    so if we add all level work done 
    then O(n) + O(n) + O(n) +.......+ k times
    k is the depth of level and by the n changing pattern (n/2^0-->n/2^1-->n/2^2--..>n/2^k)
    we can say n/2^k = 1 at last level ,
    so k= log(n)
    so work done is O(n)+.... log(n)times = log(n)*n = nlogn 

    */
    
}