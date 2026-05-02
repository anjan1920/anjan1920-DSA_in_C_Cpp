#include<iostream>

using namespace std;
//print array
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//dutch national flag
void duthNflag(int arr[], int n){

    int i=0,l=0,r=n-1; 

    while(i<=r){
        if(arr[i]==0){
            swap( arr[i],arr[l]);
            i++;
            
            l++;
        }else if( arr[i]==2){
            swap( arr[i],arr[r]);
            r--;
        }else{
            //condition when 1 fond 
            i++;
           
        }

    }
    print_arr(arr,n);
}
int main(){

    int arr[]={1,2,0,1,0,0,0,0,0,2};
    int n=8;
    print_arr(arr,n);

    duthNflag(arr,n);

}
