#include <iostream> 
#include <sstream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result; // store the uncommon words

        // Process words from the first sentence
        stringstream ss1(s1);
        string word;

        while (ss1 >> word) { // extract each word from the first sentence
            // Check if the word is present in the second sentence
            bool isInSecondSentence = false;
            stringstream ss2(s2);
            string word_s2;

            while (ss2 >> word_s2) {
                if (word_s2 == word) {
                    isInSecondSentence = true; 
                    break; 
                }
            }

            // If the word is not in the second sentence, check its occurrence in the first sentence
            if (!isInSecondSentence) {
                int occurrenceCount = 0;
                stringstream countStream(s1);
                string tempWord;

                while (countStream >> tempWord) {
                    if (tempWord == word) occurrenceCount++; // count occurrences
                }

                // If it appears exactly once, add to the result
                if (occurrenceCount == 1) result.push_back(word);
            }
        }

        // Process words from the second sentence
        stringstream ss3(s2);
        while (ss3 >> word) { // extract each word from the second sentence
            // Check if the word is present in the first sentence
            bool isInFirstSentence = false;
            stringstream ss4(s1);
            string word_s1;

            while (ss4 >> word_s1) {
                if (word_s1 == word) {
                    isInFirstSentence = true; // word is found in first sentence
                    break; 
                }
            }

            // If the word is not in the first sentence, check its occurrence in the second sentence
            if (!isInFirstSentence) {
                int occurrenceCount = 0;
                stringstream countStream(s2);
                string tempWord;

                while (countStream >> tempWord) {
                    if (tempWord == word) occurrenceCount++; // count occurrences
                }

                // If it appears exactly once, add to the result
                if (occurrenceCount == 1) result.push_back(word);
            }
        }

        return result; 
    }
};

int main() {
    Solution solution;

    // Example sentences
    string sentence1 = "apple apple banana";
    string sentence2 = "banana orange apple";

    // Get the uncommon words
    vector<string> uncommonWords = solution.uncommonFromSentences(sentence1, sentence2);

   
    cout << "Uncommon words: ";
    for (const string &word : uncommonWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0; 
}
