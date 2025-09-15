#include<iostream>
using namespace std;
double  myPow(int num ,int pow){
    //base case
    if(pow == 0) return 1;
    double ans = num*myPow(num,pow-1);
    return ans;
}
int main(){
    int x;
    int n;
    cout<<"Enter base:";
    cin>>x;
    cout<<"Enter power:";
    cin>>n;
    double ans =myPow(x,n);
    cout<<"Ans :"<<ans<<endl;

}