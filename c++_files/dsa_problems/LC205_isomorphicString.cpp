#include <iostream>
#include <string>
using namespace std;

// Leetcode 205 - Problem Statement: Isomorphic Strings
//isomorphic strings are strings that can be transformed into each other by replacing characters
//example: "egg" and "add" are isomorphic because 'e' maps to 'a' and 'g' maps to 'd'

string createStringMap(string s) {
    char map[300] = {0};   
    char start = 32; 
    // question says the string element can be any valid ASCII character 
    // and valid range of ASCII is 32 to 255
    // so we start our map with 33 which is space ' '

    for (char ch : s) {
        int char_ASCII = static_cast<int>(ch);
        if (map[char_ASCII] == 0 ) {
            map[char_ASCII] = start;
            start++;
        }
    }

    // now make the pattern using the map and return the mapped string
    string ans;
    for (char ch : s) {
        int char_ASCII = static_cast<int>(ch);
        ans.push_back(map[char_ASCII]);
    }

    return ans;
}

bool isIsomorphic(string s, string t) {
    //Approach :
    // make a map of both s and t 
    // then using the map convert the s to s_mapped string and same for t 
    // then check if they are equal or not 
    // ex say 'egg' and 'add'

    // mapping of egg : 'e'->a, 'g'->b
    // mapping of add : 'a'->a, 'd'->b 

    // now using the map of each, convert egg and add to mapped_string
    // 'egg' --> 'abb'
    // 'add' --> 'abb' 

    // both lhs is same return true

    string mappedS = createStringMap(s);
    string mappedT = createStringMap(t);
    if (mappedS == mappedT) {
        return true;
    }

    return false;

    //T.n = O(n)
}

int main() {
    string s1 = "egg";
    string s2 = "add";
    bool result = isIsomorphic(s1, s2);
    cout << "Are the strings \"" << s1 << "\" and \"" << s2 << "\" isomorphic? " 
         << (result ? "Yes" : "No") << endl;

    return 0;
}