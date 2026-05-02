//wave print of a matrix
#include<iostream>
using namespace std;

int main(){
    int matrix[][4] ={
        {1,2,3,4},
        {2,3,4,5},
        {4,5,6,7}
    };//3*4

    //wave print 
    //1 2 4 -- 2 3 5 -- 4 5 7
    //i.e when the column index is even then print in top to bottom manner
    //and when column index is odd  then print bottom to top manner



    for(int cols  = 0 ;cols  < 4 ; cols++ ){
        bool isEven = !(cols&1); // number (bitwise and) 1 == 0 if even  !0 --> 1 {true}
        if(isEven){
            //print top to bottom of the column
            for(int row = 0; row<3 ;row++){
                cout<<matrix[row][cols];
            }

        }else{
            //bottom to top print
            for(int row =  2 ;row >=0 ;row--){
                cout<<matrix[row][cols];
            }
        }
        cout<<",";
    
    }

}