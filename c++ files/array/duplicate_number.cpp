#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find_duplicate( vector<int> &arr){
    vector<int>temp=arr;
    int ans=-1;
    //sorting temp
    sort ( temp.begin() , temp.end() );

    int size = temp.size();
    for ( int i=0 ;i< size ;i++){

        if(temp[i] == temp[i+1]){
            
            ans = temp[i];
            break;

        }
    }

    return ans;
    //T.n = O(nlogn)+O(n);
}

int main(){


    vector<int>arr={1,2,3,4,5,4};
    //range is 1-n ans size of array is n+1;

    int ans = find_duplicate( arr);
    cout<<"Duplicate number is :"<<ans<<endl;





return 0;
}