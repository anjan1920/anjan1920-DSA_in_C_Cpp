#include <iostream>
#include <vector>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

    //approach-
    /* we are given mean , M dies list,n , so using this find-
    -what this what is the total sum of the n die list
    -then check if its possible or not to make the n len array-(ntotal < n || ntotal > 6 * n)-Y?
    -then start making the n list 
    -*/
    // Step 1: Calculate the total sum required
    int m = rolls.size();
    int total_sum = mean * (m + n);
    int mtotal = 0;
    int j = 0;
    while (j < rolls.size()) {
        mtotal += rolls[j];
        j++;
    }
    int ntotal = total_sum - mtotal;

    // Step 2: Check if ntotal is within valid bounds
    if (ntotal < n || ntotal > 6 * n) {
        return {};  // No valid combination exists
    }

    vector<int> missing_dice(n, 1); // initialized a n set vector to store the die with all 1 
    int remaining_sum = ntotal - n;  // We need to distribute this remain among the dice

    for (int i = 0; i < n && remaining_sum > 0; i++) {
        int add_value = min(5, remaining_sum);  // Can add at most 5 to each die
        missing_dice[i] = missing_dice[i] + add_value; // modifying the die value
        remaining_sum = remaining_sum - add_value;
    }

    return missing_dice;
}

int main() {
    // Example case
    vector<int> rolls = {3, 2, 4}; // Given rolls
    int mean = 4;                  // Target mean
    int n = 2;                     // Number of missing dice

    // Call the function to find missing rolls
    vector<int> missing_dice = missingRolls(rolls, mean, n);

    // Output the result
    if (missing_dice.empty()) {
        cout << "No valid combination exists." << endl;
    } else {
        cout << "Missing dice rolls: ";
        for (int die : missing_dice) {
            cout << die << " ";
        }
        cout << endl;
    }

    return 0;
}
