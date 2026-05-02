#include <iostream>
#include <string>
//leetcode 2325. Decode the Message
//the problem is to decode a message using a key where each character in the key maps to a unique character in the alphabet
//example: key = "anjandas", message = "nad"
//the key maps 'a' -->'a', 'n' --> 'b', 'j' --> 'c', 'd' --> 'd', 's' --> 'e'
//MESSAGE: "nad" will be decoded to ;'bad'
using namespace std;


string decodeMessage(string key, string message) {
        // Initialize an array to map each character in 'key' to a unique character
        char map[300] = {0};
        string ans;

        // Create a mapping of characters in 'key'
        char start = 'a';
        for (int i = 0; i < key.length(); i++) {
            char ch = key[i];

            // If the character is not a space and hasn't been mapped yet, assign a new character
            //map[ch] -- its visit the map char-array index position
            // which value = ascii value of the current character
            //ans it == 0 means its not visited yet
            if (map[ch] == 0 && ch != ' ') {
                map[ch] = start;
                start++;
            }
        }

        // Use the mapping to decode the message
        //now we visit the message string and for each index character and
        // we take the ascii value of the character and now we visit the index on map char-aray 
        //which value = ascii of the message character and print thr character store on the map 
        for (int i = 0; i < message.length(); i++) {
            if (message[i] == ' ') {
                // If the character is a space, add it to the result unchanged
                ans.push_back(message[i]);
            } else {
                // If the character is not a space, look up its mapped character and add it to the result
                char ch = message[i];
                ans.push_back(map[ch]);
            }
        }

        return ans;
    }


int main() {
    

    // Example usage
    string key = "anjandas";
    string message = "nad";
    string result = decodeMessage(key, message);

    // Print the result
    cout << "Original message: " << message << endl;
    cout << "Decoded message: " << result << endl;

    return 0;
}
