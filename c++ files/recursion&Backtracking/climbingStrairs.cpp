/*Q:You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?*/

/*Approach -> possible move 1 and 2 jump.
So let we reach the n'th stairs then possible way is we reach it from n-1 or n-2 stairs.
let f(n) is possible way to reach n stairs then f(n) = f(n-1)+f(n-2).
and base case f(0)--> possible way to reach the 0th stair =1
 f(1)--> possible way to reach the 1st stair =1 (0->1)
 f(2)-->possible way to reach the 2nd stair =2( 0->1->2 or 0->2)

 **Now this is nothing but a Fibonacci series

*/
#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    int ans = climbStairs(n);
    cout << "Total possible ways to reach 0 to " << n << " stairs is: " << ans << endl;
    return 0;
}
