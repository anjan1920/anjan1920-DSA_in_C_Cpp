//positive symbol using * //input should be odd
//  *
//  *
//* * *
//  *
//  *  
#include<iostream>
using namespace std;
int main(){
    int n;//input should be odd
    cout<<"Enter a odd number:";
    cin>> n;
    if(n%2==0){
        cout<<"Invalid input!!"<<endl;
    }
    else{


        int i,j;

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                //for space
                if(i%2!=0){

                    cout<<" ";
                }
                else{
                    cout<<"*";
                }  
           } 
           cout<<endl;   
    }




    }

    return 0;
}
