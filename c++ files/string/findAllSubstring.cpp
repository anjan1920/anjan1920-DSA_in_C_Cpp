#include <iostream>
#include <string>
using namespace std;

void findSubstrings(string s) {
    int n = s.length();

    // fix  i and generate all possible substring for i = 0 to last
    for (int i = 0; i < n; i++) {
        // j is possible ending points of substrings starting from index i
        for (int j = i; j < n; j++) {
            // Print the substring from index i to j length ,
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "All substrings are: " << endl;
    findSubstrings(s);

    return 0;
}
