#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},  // row 1
        {3, 4, 5, 6},  // row 2
        {9, 7, 8, 7}   // row 3
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    

    for(int i = 0; i < rows; i++) {
        for(int j = i+1; j < cols; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }

    // Output
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
