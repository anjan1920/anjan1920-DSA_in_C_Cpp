//possible move 1 or two from current stairs
//give total number of way tpo reach the nth stair

#include<vector>
#include<iostream>
using namespace  std;

int  climbStairs(int n){

    //say we are in nth stairs 
    //so no. way to reach this is 2
    //from n-1 or n-2
    //no. of way to 

    //if fn is a no of way to reach nth stair
    //then f(n) = f(n-1) ++ f(n-2) // 

    //time complexity exponential



    //base case

  

    if( n == 0) {
        //first stir
        return 1;
    }
    if( n == 1){
        //we can reach here from 0-> 1 1 way 
        return 1;
    }
    //recursion relation 
    int nWay = climbStairs(n-1) + climbStairs(n-2);

    return nWay;

}

int main(){
    int n = 50;
    
    //possible way --> 
    //1 ,1 , 1 , 
    //1 ,2 ,1
    //2,2
    //2,1,1
    //1,1,2
    //total 5 way
    int ans = climbStairs(n);
    cout<<ans;

}