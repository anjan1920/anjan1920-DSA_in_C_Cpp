#include <iostream>
#include <string>
using namespace std;

int count = 0;

/*
Approach:
1. We want to find all the permutations of a string. 
2. To do this, we'll use recursion and backtracking
   - At each recursive call, we fix one character and swap the others in the remaining part of the string.
   - For example, if the string is "anj", we fix 'a' first, then recursively swap the rest ("nj"), then fix 'n' and so on.
   - This will generate all possible combinations of characters.
3. Backtracking:
   - After swapping and making the recursive call, we need to restore the string to its previous state by swapping back. This is called backtracking.
4. Base case:
   - Once the index we're fixing reaches the end of the string, we print the current permutation.
5. We also maintain a count of the number of permutations generated.
*/

void find_allPermutation(string &s, int index) {
    // base case: if index has reached the end of the string, print the permutation
    if (index >= s.length()) {
        cout << s << ",";  // print the current permutation
        count++;           // increment the count of permutations
        return;
    }

    // Recursively swap characters and generate permutations
    for (int j = index; j < s.length(); j++) {
        // swap the current index with j
        swap(s[index], s[j]);
        // recursive call to generate permutations with the next index fixed
        find_allPermutation(s, index + 1);
        // backtrack by swapping back to restore the original string
        swap(s[index], s[j]);
    }
}

int main() {
    string s = "anj";      // input string
    find_allPermutation(s, 0);  // generate all permutations starting from index 0
    cout << endl;
    cout << count << endl;  // print the total number of permutations
}
