#include<iostream>
using namespace std;
//T.n = O(n^3)
int main(){

    int arr[5]={1,2,3,4,5};
    printf("Printing all Subarray:\n");


    for(int i =0 ;i<5;i++){
        for(int j =i ;j<5;j++){
            printf("[");

            for(int k = i ;k<=j ;k++){
            printf("%d",arr[k]);
            if(k < j){
                printf(",");
            }

            }
            printf("]");
            printf("\n");
        }
       
    
        
    }
}