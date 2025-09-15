#include<iostream>
#include<vector>

using namespace std;

vector<int> prime_list(int n) {
    // Making an array of range 0 - n + 1
    vector<bool> list(n + 1, true); // Initialize all elements to true

    // 0 and 1 are not primes
    list[0] = list[1] = false;

    // Now start from 2 to n and mark the multiples of prime as false
    for(int i = 2; i * i <= n; i++) {
        if(list[i]) {
            // If i is prime, mark its multiples as false
            for(int j = i * i; j <= n; j += i) {
                list[j] = false;
            }
        }
    }

    // Extract the prime numbers into ans vector
    vector<int> ans; 
    for(int i = 2; i <= n; i++) {
        if(list[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter upper bound: ";
    cin >> n;

    vector<int> ans = prime_list(n);

    cout << "Printing prime numbers in range of " << n << endl;
    for(auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
