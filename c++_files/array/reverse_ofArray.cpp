#include<iostream>
#include<vector>
using namespace std;

void print( vector<int>&v){

    int n = v.size();
    for( int i=0 ;i<n ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

//array reverse
void revArray(vector<int>&arr ){
    int n = arr.size();
    int i=0 ,j= n-1;//two pointer approach
    while( i<=j ){
        swap(arr[i] , arr[j] );
        i++;
        j--;
    }

    //T.n =O(n)
}

int main(){
    vector<int>arr={ 11,12,15,16,18,20};
    print(arr);
    revArray(arr);
    print(arr);


}
