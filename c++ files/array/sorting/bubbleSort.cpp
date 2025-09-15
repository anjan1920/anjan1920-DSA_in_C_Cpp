// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void show_array(int *arr,int n){
    int i = 0;
    while(i <n){
        cout<<arr[i];
        if(i != n-1){
            cout<<",";
        }
        i++;
    }
    cout<<endl;
}
int main() {
    // Write C++ code here
    int arr[5] = {2,4,3,0,1};
    
    //bubble sort
    for(int i = 0 ;i<5-1;i++){
        for(int j = 0 ;j<5-1-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
        show_array(arr,5);
    }
}