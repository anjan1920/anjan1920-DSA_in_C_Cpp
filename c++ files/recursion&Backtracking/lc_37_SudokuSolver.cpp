#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canWeplace(vector<vector<char>>& bord, int row, int col, char i){
        for(int j = 0 ; j < 9; j++){
            if(bord[row][j] == i) return false;   // row
            if(bord[j][col] == i) return false;   // col
        }

        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;

        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                if(bord[startRow + r][startCol + c] == i) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& bord){
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(bord[row][col] == '.'){
                    for(char i = '1' ; i <= '9'; i++){
                        if(canWeplace(bord,row,col,i)){
                            bord[row][col] = i;

                            if(solve(bord) == true){
                                return true;
                            } else {
                                bord[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// -------- MAIN TEST CASE ----------
int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
