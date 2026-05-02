#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for reverse

using namespace std;

class Solution {
  public:
     string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int carry = 0;
        
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? arr1[i] : 0;
            int digit2 = (j >= 0) ? arr2[j] : 0;
            
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            ans.push_back(digit);
            i--;
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        // Convert to string
        string ans_string;
        
        for (int k = 0; k < ans.size(); k++) {
            if (ans[0] == 0) continue;
            
            ans_string.push_back(ans[k] + '0');
        }
        
        return ans_string;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {9, 9, 9};
    vector<int> arr2 = {1};

    string result = sol.calc_Sum(arr1, arr2);
    cout << "Result: " << result << endl;

    return 0;
}
