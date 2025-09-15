#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//print matrix
void printMatrix(const vector<vector<int>>& matrix){
    
    int n=matrix.size();
    for (int i=0 ;i<n ;i++){
        for(int j=0 ;j<n ;j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        vector<int>ans;
       int n = mat.size();
       int count1[n];
       
       // Counting 1s in each row
       for(int i = 0; i < n; i++){
           int sum = 0;
           for(int j = 0; j < mat[i].size(); j++){
               if(mat[i][j] == 1){
                   sum++;
               }
           }
           count1[i] = sum;
       }

       // Searching for the row with the minimum number of ones
       int index;
       int max=INT_MIN;
       for(int i = 0; i < n; i++){
           if(max< count1[i]){
               max = count1[i];
               index = i;
           }
       }

      ans.push_back(index);
      ans.push_back(max);
      return ans;
    }
};
int main() {
    // Define your 2D array (matrix)
    int rows,cols;
    cout<<"Enter row and column:"<<endl;
    cin>>rows;
    cin>>cols;
    //declaration of 2d vector
    vector<vector<int>> matrix(rows, vector<int>(cols));
    //input from user;
    for(int i=0 ;i<matrix.size();i++){
        for(int j=0 ;j<matrix[i].size(); j++){

           
            cout<<" index["<<i<<","<< j<<"] Enter(0/1):";
            cin>>matrix[i][j];
           

        }
        }
        // Create an instance of the Solution class
    Solution solution;

    // Call the rowAndMaximumOnes function with the matrix as an argument
    vector<int> result = solution.rowAndMaximumOnes(matrix);

    // Print the result
    cout << "Row with maximum ones: " << result[0] << ", Count of ones: " << result[1] << endl;
    printMatrix(matrix);

    return 0;

        
        
    }

    
