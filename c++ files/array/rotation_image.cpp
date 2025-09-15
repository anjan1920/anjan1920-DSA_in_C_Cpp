//rotation of image 
// 1 2 3      7 4 1 
// 4 5 6 -->  8 5 2 
// 7 8 9      9 6 3

#include<iostream>
using namespace std;


void print(int arr[][3],int r, int c){
    for(int i=0 ;i<r ;i++){
        for(int j=0 ;j< c ;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){

    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    print(arr,3,3);
    //first we make transpose of the matrix
    cout<<" transpose"<<endl;
    for(int i=0 ;i<3  ;i++){
        for(int j=i ;j<3 ;j++){

            swap(arr[i][j],arr[j][i]);
        }
    }

    print(arr,3,3);
    //
    cout<<" Final matrix--"<<endl;
    //two pointers l and r are swap and change there position towards each other
    //3- array size, 2-- last index
    for(int i=0 ;i<3 ;i++){
        int l=0,r=2;//each time initialize l=0 and r= last index and swap,
        for(int j=0 ;l<=r  ;j++){
            swap( arr[i][l],  arr[i][r] );
            l++;
            r--;

        }
    }


 print(arr,3,3);



            






return 0;




}