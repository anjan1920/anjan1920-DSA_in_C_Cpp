#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool weCan_place(vector<string>& bord, int row, int col, int n) {
        // we want to place queen at (row, col)

        // we are placing queens column by column (left -> right)
        // so all queens are already placed in previous columns only

        // so we DON'T need to check:
        // right side, down, up, lower-right, upper-right
        // because no queen is placed there yet

        // we ONLY check 3 directions on LEFT side:
        // 1) same row (left)
        // 2) upper-left diagonal
        // 3) lower-left diagonal

        //check left
        for (int j = col - 1; j >= 0; j--) {
            if (bord[row][j] == 'Q') return false;
        }

        // upper-left diagonal
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (bord[i][j] == 'Q') return false;
            i--; j--;
        }

        //  lower-left diagona
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if (bord[i][j] == 'Q') return false;
            i++; j--;
        }

        return true;
    }

    void solve(int col, vector<string>& bord, vector<vector<string>>& ans, int n) {
        // base case: if col == n
        // means we placed all n queens successfully
        if (col == n) {
            ans.push_back(bord); // one valid board
            return;
        }

        // try placing queen in every row of this column
        for (int row = 0; row < n; row++) {
            if (weCan_place(bord, row, col, n)) {
                // place queen
                bord[row][col] = 'Q';

                // go to next column
                solve(col + 1, bord, ans, n);

                // backtrack  remove queen
                bord[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // create empty board with '.'
        vector<string> bord(n, string(n, '.'));

        vector<vector<string>> ans;
        solve(0, bord, ans, n);
        return ans;
        //Time complexity 
        /*
       “We place queens column by column. 
       The recursion tree has height n.
        At the first column we have n row choices, then at most n−1 for the next, 
        then n−2, and so on, forming a permutation-like branching pattern.
        This gives an upper bound of n! possible placement sequences.
        Each placement involves a safety check. 
        With naive scanning of rows and diagonals, that check takes O(n) time.
        So total time complexity is O(n · n!).
        space complexity will be O(n*n){bord} 
        */
    }
};

int main() {
    Solution obj;
    int n = 5;  

    vector<vector<string>> solutions = obj.solveNQueens(n);

    cout << "Total Solutions: " << solutions.size() << "\n\n";

    for (int k = 0; k < solutions.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";
        for (auto row : solutions[k]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
