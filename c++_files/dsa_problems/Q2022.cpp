#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    // First, check if it's possible to make the 2D array using the 1D array
    int cell_number = m * n;
    if(cell_number != original.size()) {
        // Return an empty vector if not possible
        return vector<vector<int>>(); // Empty vector
    }

    // Check if m = 1, then all elements are in one row
    if(m == 1) {
        vector<vector<int>> v = {original};
        return v;
    }

    // Otherwise, convert the 1D array to 2D
    vector<vector<int>> v(m, vector<int>(n));
    int k = 0; // To traverse the original vector
    for(int i = 0; i < m; i++) {
        // In each row
        for(int j = 0; j < n; j++) {
            v[i][j] = original[k];
            k++;
        }
    }
    
    return v;
}

int main() {
    vector<int> original = {1, 2, 3, 4, 5, 6};
    int m = 2;
    int n = 3;

    vector<vector<int>> result = construct2DArray(original, m, n);

    if(result.empty()) {
        cout << "Conversion not possible!" << endl;
    } else {
        cout << "2D Array:" << endl;
        for(const auto& row : result) {
            for(int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
