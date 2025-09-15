#include <iostream>
#include <vector>
#include <string>
#include <climits>
/*Note can't passed all test cases due to time complexity*/
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    int n = s.length(); 
    vector<string> mystring; // Vector to store the substrings

    // Special case for empty string
    if (n == 0) {
        return 0;
    }

    for (int start = 0; start < n; ++start) {
        for (int end = start + 1; end <= n; ++end) {
            // Get the substring from index 'start' to 'end-1'
            string temp = s.substr(start, end - start);
            
            // Check if the substring contains duplicate characters
            bool flag = true;
            for (int k = 0; k < temp.length(); ++k) {
                char ch = temp[k];
                size_t pos = temp.find(ch);
                if (pos != k) { // If character is found at a position different from the current index, it's a duplicate
                    flag = false;
                    break;
                }
            }

            // Add the substring to the vector if it does not contain duplicates
            if (flag) {
                mystring.push_back(temp);
            }
        }
    }

    // Find the maximum length substring and return its length
    int max_length = INT_MIN;
    for (int i = 0; i < mystring.size(); ++i) { 
        int len = mystring[i].length();
        if (len > max_length) {
            max_length = len; // Update the maximum length
        }
    }

    return max_length; // Return the length of the longest substring
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring with unique characters: " << result << endl;

    return 0;
}
