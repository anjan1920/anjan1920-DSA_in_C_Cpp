#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int reverse = 0; // store the reverse number
    while (n > 0) {
        int lastDigit = n % 10; // store the last digit in each iteration
        reverse = reverse * 10 + lastDigit; // build the reverse number by adding the last digit

        n = n / 10; // remove the last digit from the original number
    }

    cout << reverse << endl; // print the reverse number
    return 0;
}
