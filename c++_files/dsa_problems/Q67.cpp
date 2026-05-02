#include<iostream>
#include<string>
#include<algorithm> // For reverse function
using namespace std;

int main() {
    // Input binary strings
    string a = "1011";
    string b = "1101";

     
    // Binary sum
    string b1 = a;
    string b2 = b;
    int i = b1.size() - 1;
    int j = b2.size() - 1;
    int carry = 0;
    string sum;

    while (i >= 0 || j >= 0) {

        int bit1 = (i >= 0) ? int(b1[i] - '0') : 0; // If i >= 0, bit1 = b1[i] - '0', else bit1 = 0
        int bit2 = (j >= 0) ? int(b2[j] - '0') : 0;// b1[i]-'0' give ascii of 0 or 1 then  int(b1[i]-'0') convert it to int value
        if (bit1 + bit2 == 1 && carry == 0) {
            sum.push_back('1');
            carry = 0;
        }else if (bit1 + bit2 == 2 && carry == 0) {
            sum.push_back('0');
            carry = 1;
        } else if (bit1 + bit2 == 1 && carry == 1) {
            sum.push_back('0');
            carry = 1;
        } else if (bit1 + bit2 == 2 && carry == 1) {
            sum.push_back('1');
            carry = 1;
        } else if (bit1 + bit2 == 0 && carry == 1) {
            sum.push_back('1');
            carry = 0;
        } else {
            sum.push_back('0');
            carry = 0;
        }

        i--;
        j--;
    }

    // If there's still a carry after the loop, add it to the sum
    if (carry == 1) {
        sum.push_back('1');
    }

    // Reverse the result to get the correct binary sum
    reverse(sum.begin(), sum.end());


    // Output the result
    cout<< "Sum: " << sum << endl;

    return 0;
}


