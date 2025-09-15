#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//n is said to be ugly number if its all factors are limited to 2,3,5 
/*if n is ugly then n*2,n*3,n*5 is also ugly*/

int nthUglyNumber(int n) {
    if (n == 1) return 1;
    if (n < 1) return -1;

    // Vector to store the ugly numbers
    vector<int> ugly_list;
    ugly_list.push_back(1);

    int u1 = 2, u2 = 3, u3 = 5;//factors of ugly 
    int i1 = 0, i2 = 0, i3 = 0; // Indices for multiples of 2, 3, and 5

    while (ugly_list.size() < n) {
        //finding the next ugly 
        int nextUgly1 = ugly_list[i1] * u1;
        int nextUgly2 = ugly_list[i2] * u2;
        int nextUgly3 = ugly_list[i3] * u3;

        // Find the minimum among these ugly numbers and push it to the vector
        int nextUgly = min({nextUgly1, nextUgly2, nextUgly3});
        ugly_list.push_back(nextUgly);

        // Move the pointer for the appropriate factor so that any ugly number is not get missed
        if (nextUgly == nextUgly1) i1++;//if pushed ugly is nextugly1 then move the pointer i1 to that 
        if (nextUgly == nextUgly2) i2++;
        if (nextUgly == nextUgly3) i3++;
    }

    return ugly_list[n-1];
    //T.n = O(n) while loop 
}

int main() {
    int n = 10;
    int result = nthUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << result << endl;
    return 0;
}
