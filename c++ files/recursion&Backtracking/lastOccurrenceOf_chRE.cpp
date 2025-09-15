#include <iostream>
using namespace std;

// Recursive function to find the last occurrence of ch in str
int lastOccurrence(string &str, char ch, int index) {
    // Base case: if index is out of bounds
    if (index < 0) {
        return -1;  // Character not found
    }

    // Check if the current character matches ch
    if (str[index] == ch) {
        return index;  // Return the index of the last occurrence
    }

    // Recursive call: move to the previous index
    return lastOccurrence(str, ch, index - 1);
}

int main() {
    string str = "abbaacc uuiiabba";
    char ch = 'a';
    int length = str.length();
    int findIndex = lastOccurrence(str, ch, length - 1);
    cout << findIndex << endl;
    return 0;
}
