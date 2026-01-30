#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canWeplace(vector<vector<char>>& bord, int row, int col, char i){
        for(int j = 0 ; j < 9; j++){
            //row condition
            if(bord[row][j] == i) return false;
            //col conditon
            if(bord[j][col] == i) return false;
        }

        //sub grid conditin
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
                //if  empty cell
                if(bord[row][col] == '.'){
                    //ty to fill with 1 to 9

                    for(char i = '1' ; i <= '9'; i++){
                        if(canWeplace(bord,row,col,i)){
                            //true
                            bord[row][col] = i;
                            //recusrion call to fill next empty 
                            if(solve(bord) == true){
                                //the next all empty spaces get filed
                                //so current i is a valid for next combinations
                                return true;
                            }else{
                                //if we place current i here now
                                //we cant place any i on the next any of one empty place
                                //so remove it
                                bord[row][col] = '.';
                            }

                        }else{
                            //cant try next i
                            continue;
                        }
                    }
                    //we cant palce any i on the empty space
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
