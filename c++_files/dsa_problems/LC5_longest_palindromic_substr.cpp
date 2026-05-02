#include <string>
#include <iostream>
using namespace std;
// Leetcode 5 - Problem Statement: Longest Palindromic Substring
// The problem is to find the longest palindromic substring in a given string.
//example: Given the string "babad", the longest palindromic substring is "bab" or "aba".

// function to find the longest palindromic substring around the center
string expand_around_center(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the longest palindrome found by adjusting indices after loop exit
    return s.substr(left + 1, right - left - 1);
}



string longest_palindrome(string s) {
    string longestPalindrome = "";

    // For odd-length palindromes: center at a single character
    for (int center = 0; center < static_cast<int>(s.length()); center++) {
        string palindrome1 = expand_around_center(s, center, center);
        if (palindrome1.length() > longestPalindrome.length()) {
            longestPalindrome = palindrome1;
        }

        // For even-length palindromes: center between two characters
        string palindrome2 = expand_around_center(s, center, center + 1);
        if (palindrome2.length() > longestPalindrome.length()) {
            longestPalindrome = palindrome2;
        }
    }

    return longestPalindrome;
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    //The approach is we will find the lognest palindromic substring of odd and even length substring
    //For that we use two pinter approach and start from a index ( called center )of the string
    //the center will be the current character and the next character for the even length substring
    //and for odd length substring the center will be the current character only

    //now we expand outwards from the center by l-- and r++ until we find the characters are not same
    //and we will return the longest palindromic substring found 
    
    string result = longest_palindrome(s);
    cout << "Longest palindromic substring: " << result << endl;

    return 0;
}