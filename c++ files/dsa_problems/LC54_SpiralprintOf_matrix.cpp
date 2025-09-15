#include <iostream>
#include <vector>
using namespace std;

vector<int>SpiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
        vector<int>ans;

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int  bottom = matrix.size() - 1;
        int matrixElement = matrix.size() * matrix[0].size();

        while (matrixElement > 0) {
            // Print top row (left to right)
            for (int i = left; i <= right && matrixElement > 0; i++) {
                //cout << matrix[top][i] << " ";
                ans.push_back(matrix[top][i]);
                matrixElement--;
            }
            //shift top to next row
            top++;

            // Print right column (top to bottom)
            for (int i = top; i <= bottom && matrixElement > 0; i++) {
                ans.push_back(matrix[i][right]);
                matrixElement--;
            }
            //move the right pointer
            right--;

            // Print bottom row (right to left)
            for (int i = right; i >= left && matrixElement > 0; i--) {
                ans.push_back(matrix[bottom][i]);
                matrixElement--;
            }
            bottom--;

            // Print left column (bottom to top)
            for (int i = bottom; i >= top && matrixElement > 0; i--) {
                 ans.push_back(matrix[i][left]);
                matrixElement--;
            }
            left++;
        }

        return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {0,66,44,12}
    };

    vector<int>spiralPrint = SpiralOrder(matrix);
    cout<<"Spiral print :";
    for(auto val : spiralPrint){
        cout<<val<<' ';
    }
    return 0;
}
