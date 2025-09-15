#include<iostream>
using namespace std;
int main(){
    int i,n;
    cout<<"Enter the number:";
    cin>>n;
    cout<<"Table of "<<n<<" is--"<<endl;
    for(i=1;i<=10;i++){
        cout<<n<<"*"<<i<<"="<<(n*i)<<endl;
    }

 return 0;      
}