#include<iostream>
using namespace std;
//digit of a number
void print_digit(){
    int num;
    cout<<"Enter number:";
    cin>>num;
    int temp=num;
    //reverse of the number
    int reverse=0;
    while(temp>0){
        int lastdigit=temp%10;
        reverse=reverse*10+lastdigit;
        temp=temp/10;


    }

   // cout<<"Reverse of number:"<<reverse<<endl;
    cout<<"Digit of a the number are--"<<endl;
    //digit print
    while(reverse>0){
        int digit=reverse%10;
        cout<<digit<<"\t"<<endl;
        reverse=reverse/10;
    }



}

int main(){
    print_digit();
    
}

