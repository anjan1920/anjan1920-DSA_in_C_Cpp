#include<iostream>
#include<vector>
using namespace std;


int fib(int n,vector<int>&v){

    //every time we check if the value is already present in the vector or not i.e no more recursive calls
    //if  its present then we dont calculate it again

    //base case
    
    if( n== 0) return 0;
    if(n == 1) return 1;
    int num1  = n-1;
    int num2 = n-2;
    //if the value is already present in the vector then we return the value
    if(v[num1] != -1) num1 = v[num1];
    else{
        //if the value is not present in the vector then we calculate it and store it in the vector
        num1 = fib(n-1,v);
        v[n-1] = num1;
    }

    if(v[num2] != -1) num2 = v[num2];
    else{
        num2 = fib(n-2,v);
        v[n-2] = num2;
    }
    int ans = num1 + num2;
    return ans;

    
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    vector<int>record(n+1,-1);
   
    int nthTerm = fib(n,record);
    cout<<n<<"th term of fibonacci series is: "<<nthTerm<<endl;
    return 0;
    

}