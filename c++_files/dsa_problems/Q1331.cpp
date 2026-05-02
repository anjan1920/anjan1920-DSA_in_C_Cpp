#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {}; //empty case

       //take all unique vales
        set<int> s(arr.begin(), arr.end());

        //sort the unique vales and store in a vector
        vector<int> sorted_vals(s.begin(), s.end());

        //give rank
        vector<int> rank(sorted_vals.size());

        int rank_i = 1;
        for (int i = 0; i < sorted_vals.size(); i++) {
        
            rank[i] = rank_i++;
        }

       // now map the values with is rank
        map<int, int> value_to_rank;
        for (int i = 0; i < sorted_vals.size(); i++) {
            value_to_rank[sorted_vals[i]] = rank[i];//sorted_val[i] is key and rank[i] is value of the key
            /*
             sorted_values[i] ---> rank[i];
            */
        }

        //ans vector
        vector<int> result;
        for (int val : arr) {
            int rankOf_val = value_to_rank[val];// returns the rank of 'val' data
            result.push_back(rankOf_val);
        }

        return result;
    }
};

        
    


int main() {
    Solution sol;
    
    // Input array
    vector<int> arr = {40, 10, 20, 30,41,55,1,10};

    // Call the arrayRankTransform function
    vector<int> result = sol.arrayRankTransform(arr);

    // Print the result
    cout << "Rank-transformed array: ";
    for (int rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
