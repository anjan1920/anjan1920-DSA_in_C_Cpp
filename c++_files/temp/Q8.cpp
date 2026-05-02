#include <iostream>
#include <string>
#include <climits> 
#include <cctype>  // For isdigit
using namespace std;

int myAtoi(string s) {
    int i = 0;
    long num = 0; // Use long to avoid overflow during computation
    int sign = 1;

    // Remove leading spaces
    while (i < s.size() && s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Move i until it is a digit
    while (i < s.size() && isdigit(s[i])) {
        // Check for overflow before adding the next digit
        //if  the num is just == int max/10 i.e 2,147,483,64 . and the last digit is 0-6 range.
        // then we have to return that i.e 2,147,483,64X (0<=x<=6) 
        //so if the s[i] is 0-6 and the num = INT_MAX/10 then compute num = num*10+s[i];
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = num * 10 + (s[i] - '0');
        i++;
    }

    // Return the number with the sign
    return num * sign;
}

int main() {
    string input;
    cout << "Enter a string to convert to an integer: ";
   getline(cin, input); // Read the entire line to include spaces

    int result = myAtoi(input);
    cout << "Converted integer: " << result << endl;

    return 0;
}
