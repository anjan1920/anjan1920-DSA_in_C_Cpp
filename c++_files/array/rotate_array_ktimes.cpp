#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int>&v){
    for(auto val :v){
        cout<<val<<" ,";
    }
}



void rotate_array(vector<int>&v,int k){

    while(k != 0){
        //one time rotation logic 
        //-start from last index swap it with prev once
        //-move the pointer to prev (i.e i--)
    for(int i = v.size()-1 ;i>0;i--){
            swap(v[i],v[i-1]);

    }
        k--;

    }

    //Time complexity -- O(k)*O(n) ~O(nk)

}

int main(){


    int size;
    cout<<"Enter array size:";
    cin>>size;
    vector<int>arr(size);

    cout<<"Enter array elements .\n";
    for(int i = 0 ;i<size; i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter how many times to rotate:";
    cin>>k;
    //main array: 1,2,4,5,6
    //1st rotation -> 6,1,2,4,5 -
    //2nd rotation -> 5,6,1,2,4

    //*if a array size is n , then after n rotation its become original array
    //optimize no of rotation = k%n
    int  rotation_no = k%size;
    cout<<"Given array:";
    print_array(arr);

    //function call
    rotate_array(arr,rotation_no);
    cout<<"After rotating "<<k<<" times Final array:";
    print_array(arr);



}

