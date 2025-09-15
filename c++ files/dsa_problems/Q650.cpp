#include<iostream>
using namespace std;

/* Find all factors of the n and return the sum of that */

int minSteps(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {  // While i divides n, keep dividing n by i
            ans += i;  // Add i to the answer (i steps: 1 Copy All and i-1 Paste operations)
            n /= i;  // Reduce n by dividing it by i
        }
    }
    return ans;  // Return the total number of operations needed
}

int main() {
    int n = 9;
    int result = minSteps(n);
    cout << "Minimum steps to get " << n << " 'A's: " << result << endl;
    return 0;
}
