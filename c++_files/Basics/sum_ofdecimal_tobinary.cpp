#include<iostream>
#include<cmath>
using namespace std;
int main(){
int x,y;
cout<<"Enter two decimal number"<<endl;
cin>>x;
cin>>y;

    int n=x+y;
    
    int digit=0;
    int ans=0;
    
    
    while(n!=0){
        digit =n%2;
        ans = ans*10 +digit;
        n=n/2;

        
        }
    //cout <<ans<<endl;
 //reverse of ans is final binary number
 int last_digit=0;
 int final_ans=0;

 while(ans!=0){
    last_digit= ans%10;
    final_ans =final_ans*10 + last_digit;
   ans =ans/10;

 }
cout<<"The sum is :"<<(x+y)<<endl;
cout<<"Binary number is :"<<final_ans;
    return 0;
}