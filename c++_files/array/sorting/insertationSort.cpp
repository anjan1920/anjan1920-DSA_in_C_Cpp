//insertion Sorting
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

void insertionSort(vector<int>&arr){

    int n = arr.size();
    int i=1;
   // Iterate through each element in the array starting from the second element
    for( int i=1 ;i<n ;i++){
        int key =arr[i];
        int j = i-1;
        // Move elements greater than key to one position ahead of their current position
        while( j>=0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
            //we shift the element without swaping 
        }
        arr[ j+1 ] = key;

    }

}
int main(){
    vector<int>arr ={ 23,1,10,5,2};
    insertionSort(arr);
    print(arr);
}