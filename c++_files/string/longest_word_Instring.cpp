#include<iostream>
#include<cstring>
using namespace std;

void find_longestWord_charArr(char str[]) {
    int maxLength = 0, maxStart = 0;
    int length = 0;  // Current word length
    int start = 0;

    for (int i = 0; str[i] != '\0'; i++) {

        // Space or last index --> new word
        if (str[i] == ' ' || str[i + 1] == '\0') {

            // Last word case (if last character is not a space)
            if (str[i + 1] == '\0') length++;  
            //space case
            if (length > maxLength) {
                maxLength = length;
                maxStart = start;
            }

            length = 0;  // Reset length for new word
            start = i + 1;  // New start index (after space)
        } else {
            length++;  // Increase length for the current word
        }
    }

    // Print the longest word
    cout << "Longest length word is: ";
    for (int j = maxStart; j < maxStart + maxLength; j++) {
        cout << str[j];
    }
    cout << endl;
}

int main() {
    char sentence2[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence2, 100);

    find_longestWord_charArr(sentence2);

    return 0;
}
