
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

    bool inVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // Function to generate all substrings of a string
    void findSubstrings(string &s, vector<string> &all_subStr) {
        int n = s.length();

        // Generate all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string subStr = s.substr(i, j - i + 1);
                all_subStr.push_back(subStr);
            }
        }
    }

    int countOfSubstrings(string &word, int k) {
        vector<string> all_subStr;
        findSubstrings(word, all_subStr);

        // Now check how many substrings have all vowels and exactly k consonants
        int count = 0;
        for (int i = 0; i < all_subStr.size(); i++) {
            int count_conso = 0;
            bool check_vowel[5] = {false}; // 0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
            string sub = all_subStr[i];

            // Iterate over each character in the substring
            for (int j = 0; j < sub.length(); j++) {
                if (!inVowel(sub[j])) { // Count consonants
                    count_conso++;
                } else { // Check vowels
                    if (sub[j] == 'a') check_vowel[0] = true;
                    if (sub[j] == 'e') check_vowel[1] = true;
                    if (sub[j] == 'i') check_vowel[2] = true;
                    if (sub[j] == 'o') check_vowel[3] = true;
                    if (sub[j] == 'u') check_vowel[4] = true;
                }
            }

            // Check if the substring has exactly k consonants and all vowels
            if (count_conso == k &&
                check_vowel[0] && check_vowel[1] && check_vowel[2] && 
                check_vowel[3] && check_vowel[4]) {
                count++;
            }
        }

        return count;
 }

 int main(){

    string word  =  "ieaouqqieaouqq";
    int  k = 1;
    int value = countOfSubstrings(word, k);
    cout<<"No.of substring, contain every vowel & exactly," <<k<<"
     consonants is:"<<value<<endl;
 }


