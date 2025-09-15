//sum of digit
#include<iostream>
 using namespace std;

 int main(){
    int n;
    cin>>n;
   

    int digit,temp=0;
    //
    while(n>0){ 
    digit =n%10;//store last digit in each iteration
   
    temp=temp+digit;//addding each digit
    n=n/10;//remove last digit from number
    }
    cout <<temp<<endl;
    return 0;
 }