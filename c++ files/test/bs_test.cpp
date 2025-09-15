#include<iostream>
#include<vector>
using namespace std;

//binary search

int main(){

    vector<int> v= { 1,5,9,10,11};
    int target = 15;

    int l = 0 ;
    int h = v.size()-1;

    while( l <= h){
        int mid = l + ( h - l);

        if(v[mid] == target) {
            cout<<"Target found at index : "<<mid<<endl;
            return 0 ;
        }else if(v[mid] < target) l = mid +1;
        else {
            h = mid -1;
        }
    }

    cout<<"Target Not found:"<<endl;
    return 1;

    
}