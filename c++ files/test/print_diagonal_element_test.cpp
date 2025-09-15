#include<iostream>
#include<vector>

using namespace std;


int main(){

    vector<vector<int>>matrix = {
        {1,2,3,4},
        {4,5,6,7},
        {8,9,10,11},
        {0,55,66,88}
    };
    //expected --> 1,5,6,10

    int rows = matrix.size();
    

    for(int i = 0 ;i<rows ;i++){
        cout<<matrix[i][i]<<",";

    }

    return 0;
}