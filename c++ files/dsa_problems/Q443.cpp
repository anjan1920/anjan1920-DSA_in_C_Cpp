#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compress the character vector
int compress(vector<char>& chars) {
    // Corner case
    if (chars.size() == 1) return 1;

    int s = 0; // Start pointer
    int e;     // End pointer
    string str = ""; // To hold compressed string

    while (s < chars.size()) {
        e = s + 1; // Initialize end pointer
        int count_ch1 = 1; // Count occurrences
        char ch1 = chars[s]; // Current character
        
        // Count frequency of ch1
        while (e < chars.size() && chars[e] == ch1) {
            count_ch1++;
            e++;
        }

        // Add character to string
        str.push_back(ch1);
        if (count_ch1 > 1) {
            str += to_string(count_ch1); // Add count if greater than 1
        }

        // Move to the next new character
        s = e;
    }

    // Modify the original given char array 
    for (int i = 0; i < str.length(); i++) {
        chars[i] = str[i]; // Update chars with compressed values
    }

    return str.length(); // Return new length
}

int main() {
    // Create a sample character vector
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    // Call the compress function
    int newLength = compress(chars);
    
    // Print the compressed array
    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i]; // Output each character in the compressed array
    }
    cout << endl;

    return 0; // Exit the program
}
