
#include <iostream>
#include <vector>
using namespace std;

vector<int> binary2D(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int s = 0, e = m * n - 1;
    //lets imagine we working on a 1d array so total size = m*n, 
    //now we have to map the  of this m*n size 1d array -- 2d matrix index
    //formula --we randomly chose a index x in 1d array, value insert on x index = 2Darr[row][coumn]
    //row index = x/n (n=column of 2d). column = x%n
    vector<int> ans = {0, -1}; // Initializing with values -1 indicating 'Not Found'

    while (s <= e) {

    
        int mid = s + (e - s) / 2;
        int rowindex = mid / n;
        int colindex = mid % n;
        int currentNumber = matrix[rowindex][colindex];

        if (currentNumber == target) {
            ans[0] = rowindex;
            ans[1] = colindex;
            return ans;
        } else if (currentNumber < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;

    //T.n=O(log m*n)
}

int main() {
    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> matrix = { {4, 5, 6, 7}, {10, 11, 12, 13}, {15, 16, 17, 18} };
    vector<int> ans = binary2D(matrix, target);

    if (ans[0] == -1 ) {
        cout << "Not present" << endl;
    } else {
        cout << "Target present on index " << ans[0] << ", " << ans[1];
    }

    return 0;
}
