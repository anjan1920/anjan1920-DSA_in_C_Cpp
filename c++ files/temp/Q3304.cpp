#include <iostream>
#include <cmath>
#include <string>
using namespace std;

char kthCharacter(int k) {
    string ans = "a";
    int x = k;
    // each time ans size is increasing at rate of 2^x, i.e "size(x) = 2^x", x is no. of iteration 
    // now for getting at least k size ans string, no of iteration "x = ceiling value[log(k)/log(2)] "
    x = ceil(log(k) / log(2)); // "ceil()" returns ceiling value

    while (x > 0) {
        // traverse each character of the ans string and find the next character of each
        string next = "";
        for (int i = 0; i < ans.length(); i++) {
            int next_chASCII = int(ans[i]) + 1;
            if (next_chASCII == int('z')) next_chASCII = int('a');
            char next_ch = char(next_chASCII);
            next += next_ch;
        }
        ans += next;
        next.erase();
        x--;
    }

    // return k'th character i.e k-1 index
    return (ans[k - 1]);
}

int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "The " << k << "th character is: " << kthCharacter(k) << endl;
    return 0;
}
