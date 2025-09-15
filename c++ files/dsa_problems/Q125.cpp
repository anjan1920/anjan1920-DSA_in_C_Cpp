#include<iostream>
#include<string.h>

using namespace std;
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            char chl = s[start];
            char chr = s[end];

            // Skip non-alphabetic characters 
            /*isalnum(ch)-->
            :Returns true if the character is either a letter (uppercase or lowercase) or a digit (0-9).
            :Returns false if the character is any other symbol, space, or punctuation mark.*/
            if (!isalnum(chl)) {
                start++;
                continue;
            }
            if (!isalnum(chr)) {
                end--;
                continue;
            }

            // Convert both to lowercase for comparison
            if (chl >= 'A' && chl <= 'Z') {
                chl += 32;  // Convert uppercase to lowercase
            }
            if (chr >= 'A' && chr <= 'Z') {
                chr += 32;  // Convert uppercase to lowercase
            }

            // Compare characters
            if (chl != chr) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
int main(){
    string s ="A man, a plan, a canal: Panama";
    if(isPalindrome(s)){
        cout<<"String is palindrome.";
    }
    return 0;

}
