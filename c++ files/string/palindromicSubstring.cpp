//647. Palindromic Substrings
#include<iostream>
#include<string>
using namespace std;


    // Helper function to check and count palindromic substrings
int checkPalindrome(string str, int l, int r) {
        int count = 0;
        // Expand the substring in odd and even manner by moving l and r outwards
        // Increase the count each time a palindrome is found (when str[l] and str[r] are equal)
        while (l >= 0 && r < str.length() && str[l] == str[r]) {
            count++;
            l--;  // Move left pointer towards the start of the string
            r++;  // Move right pointer towards the end of the string
        }
        return count;
    }


    // Function to count all palindromic substrings in the given string
    int countSubstrings(string s) {
        int count = 0;
        // Iterate through the string with each character as the potential center of the palindrome
        for (int center = 0; center < s.length(); center++) {
            // Check for palindromes with the current character as the center for odd-length substrings
            int countOdd = checkPalindrome(s, center, center);
            // Check for palindromes with the current character and the next character 
            //as centers for even-length substrings
            int countEven = checkPalindrome(s, center, center + 1);
            // Accumulate the counts
            count = countOdd + countEven + count;
        }
        return count;
    }


int main(){

    string s;
    cout<<"Enter string:";
    getline(cin,s);
    int ans = countSubstrings(s);
    cout<<"Total palindromic substring :"<<ans<<endl;


}