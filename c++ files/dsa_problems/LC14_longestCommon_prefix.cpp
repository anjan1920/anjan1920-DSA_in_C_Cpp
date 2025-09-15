#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//Leetcode 14 - Problem Statement: Longest Common Prefix
//example: Given a list of strings ["flower", "flow", "flight"],
 //the longest common prefix is "fl".

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    if (strs.empty()) return "";

    // first sort the vector 
    sort(strs.begin(), strs.end()); // lexicographical order (dictionary order)

     //Step-by-step lexo sorting --
    // 1. All start with 'f' 
    // 2. Second char 'l' same
    // 3. Third char: "flower" → 'o', "flow" → 'o', "flight" → 'i'
    //   Since 'i' < 'o'{i comes before o } → "flight" comes before the other two
    // Final sorted order: ["flight", "flow", "flower"]


    // After sorting, the first and the last strings will be the most different.
    //So the common prefix between them 
    //will be common to all strings in the list

    int n = strs.size();

    string first_word = strs[0];
    string last_word = strs[n - 1];

    // now find the common prefix between them
    string ans = "";
    for (int i = 0; i < min(first_word.size(), last_word.size()); i++) {
        if (first_word[i] == last_word[i]) {
            ans.push_back(first_word[i]);
        } else {
            // mismatch  return the result upto that
            return ans;
        }
    }

    return ans;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

   return 0;
}
