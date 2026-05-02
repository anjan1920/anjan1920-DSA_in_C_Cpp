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
void insercationSort(vector<int>&arr){

    int n = arr.size();
    int i=1;
    for( i=1 ;i<n ;i++){
        int key = arr[i];
        for(int j=i ;j>=0 ;j-- ){
            if(arr[j-1] > key && j-1>=0){
                swap( arr[j] ,arr[j-1]);
                 
            }
        }
    }
   
   print(arr);

    
}
int main(){
    vector<int>arr;
    arr={22,55,1,0,66,88};
    
    insercationSort(arr);


}
