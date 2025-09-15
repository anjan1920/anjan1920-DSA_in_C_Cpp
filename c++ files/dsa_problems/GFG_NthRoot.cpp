#include<iostream>
using namespace std;
//Problem :GFG Find nth root of m
///You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.
//example:
// Input: n = 3, m = 27
// Output: 3
// Explanation: (27)^1/3 or 3root (27) = 3  or pow(3,3) =27

class Solution {
public:
    long calPow(long base, int exponent, long m) {
        long result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
            
            //no need to calculate more it cant not be the ans returrn upto that
            if (result > m) return result; 
        }
        return result;
    }

    int nthRoot(int n, int m) {
        long s = 1;
        long e = m;
        int ans = -1;

        while (s <= e) {
            long mid = s + (e - s) / 2;
            long midPow = calPow(mid, n, m);//calculate the power of mid 

            if (midPow == m) {
                ans = mid;
                return mid;
            } else if (midPow < m) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main(){

    int n ;
    int m;
    cin>>n>>m;
    Solution* obj;
    int ans = obj->nthRoot(n,m);
    cout<<ans<<endl;
    return 0;

}