#include<iostream>
using namespace std;
//even or odd using bit wise
int even_odd_bit(){
    int num;
    cout<<"Enter a number to check even or odd:";
    cin>>num;
    int flag=0;
    if((num & 1)==0){//do and operation number(binary) and  01 
    //for even ex 4=100 &001 =0
        flag=0;

    }else{
        flag=1;
    }

    if(flag==0){
        cout<<"its even.";
    }else{
        cout<<"its odd.";
    }
}
int main(){
    even_odd_bit();

}