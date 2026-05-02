#include <iostream>
#include <string>
using namespace std;

//Approaching this,
        // create a char array with an index that represents the letter "s"
        // and the data on that index is the character "t", which is now mapped to that index.
        //creat a second map to monitor whether or not the character of "t" is mapped.
        // following mapping ---
        // begin traversing the s,
        // visit the relevant index in the char array
        // extract the data (ch) present on that and append to a string
        // at the end if the string == t then return true;

bool isIsomorphic(string s, string t) {
    char charMap[300] = {0}; 
    bool charUsed[300] = {false};
    int i = 0;
    int length = s.length(); 

    if (length != t.length()) {
        return false; 
    }

    while (i < length) {
        int sCharIndex = int(s[i]); // ASCII value of "s" character
        char tChar = t[i]; // Character of "t" which is going to map with that index 

        // Make map if "s" relevant index is free and character of "t" not mapped yet
        if (charMap[sCharIndex] == 0 && !charUsed[int(tChar)]) { 
            charMap[sCharIndex] = tChar;
            charUsed[int(tChar)] = true;
        }
        i++;
    }

    string temp = "";
    int index = 0;
    while (index < s.length()) {
        int mappedIndex = int(s[index]);
        char mappedChar = charMap[mappedIndex];
       
        temp += mappedChar; 
        index++;
    }
   
    return temp == t;
}

int main() {
    string s, t;
    s = "egg";
    t = "add";

    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
