#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

// Use a map to count the occurrences of each character in the first string.
//Traverse the second string, decrementing the counts in the map for each character found.
//If at any point a count<0, it 
//indicates that the second string has more of that character than the first string and they are not anagram
    bool checkAnagram(string &str1, string &str2) {
        
        if (str1.length() != str2.length()) {
            return false;
        }

        int map[256] = {0}; 

        
        for (char c : str1) {
            map[c]++;
        }

        for (char c : str2) {
            map[c]--;
            
            if (map[c] < 0) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                // Skip already processed strings
                continue;
            }
            
            string str1 = strs[i];
            vector<string> group; // Vector to hold anagrams
            group.push_back(str1); // Add the base string to the group
            visited[i] = true; // Mark this string as visited

            for (int j = i + 1; j < n; j++) {
                if (checkAnagram(str1, strs[j]) && !visited[j]) {
                    group.push_back(strs[j]);
                    visited[j] = true; // Mark this anagram as visited
                }
            }

            ans.push_back(group); // Add the group of anagrams to the result
        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);

    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
