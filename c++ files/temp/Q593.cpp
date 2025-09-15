#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4) {
    //approach
    /*Step 1: Calculate the pairwise distances.
    Step 2: Sort the distances.
    Step 3: Check the first four distances 
     -are equal (sides) and the last two are equal (diagonals),
      -and the diagonal is root times the side.*/

    vector<vector<int>>pairs2d = { {p1}, {p2}, {p3}, {p4} };

    vector<double>ans; // size ans vector first 4 index -> side last 2 index -> diagonals

    // Generate all pairs (6 pairs)
    for(int i = 0; i < 4; i++) {
        // For ith point generate i+1 -> remaining point pair
        for(int j = i + 1; j < 4; j++) {
            vector<int> P1 = pairs2d[i];
            vector<int> P2 = pairs2d[j];

            int a = P1[0];
            int b = P1[1];
            int A = P2[0];
            int B = P2[1];

            // Calculate distance
            double distanceSqr = ((A - a) * (A - a) + (B - b) * (B - b));
            ans.push_back(distanceSqr);
            // Remove the root in the equation to avoid precision issues
            // Now distance is actually stored as the square value of the distance
        }
    }

    // Now sort the ans vector
    sort(ans.begin(), ans.end());
    // Check if last index value (diagonal) = 2 * 0th index value or not
    double side = ans[0];
    double diagonal = ans[ans.size() - 1];
    return (diagonal == 2 * side && side != diagonal);
}

int main() {
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 0};
    vector<int> p3 = {0, 1};
    vector<int> p4 = {1, 1};

    bool result = validSquare(p1, p2, p3, p4);
    cout << (result ? "The points form a square." : "The points do not form a square.") << std::endl;

    return 0;
}
