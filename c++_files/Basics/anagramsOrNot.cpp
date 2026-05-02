#include <iostream>
#include <string>
using namespace std;

// Use a map to count the occurrences of each character in the first string.
//Traverse the second string, decrementing the counts in the map for each character found.
//If at any point a count<0, it 
//indicates that the second string has more of that character than the first string and they are not anagram

bool checkAnagram(string &str1, string &str2) {
    // If lengths are different can't be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    int map[300] = {0}; 

    // Count occurrences of each character in str1
    for (char c : str1) {
        map[c]++;
    }

    // Subtract occurrences of str2 from str1
    for (char c : str2) {
        map[c]--;
        // If count goes negative, str2 has extra characters i.e not anagram
        if (map[c] < 0) {
            return false;
        }
    }

    // If we reach here, they are anagrams
    return true;
}

int main() {
    string str1 = "nat";
    string str2 = "tan";
    if (checkAnagram(str1, str2)) {
        cout << "'" << str1 << "' & '" << str2 << "' are anagrams." << endl;
    } else {
        cout << "'" << str1 << "' & '" << str2 << "' are not anagrams." << endl;
    }

    //Time complexity O(n)
}
