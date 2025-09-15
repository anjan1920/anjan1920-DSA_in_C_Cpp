#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        //sort the array
        sort(nums.begin(), nums.end());

        // Pick the first element as it's the smallest among all.
        // Set the target to the second element, and the goal is to
        // make the selected element equal to the second one. 
        // To do that, we need to increase the first element by the difference between the second and first, 
        // and increase all other elements except the second by the same difference 
        // (as per the question condition where we can increase n-1 elements).
        // Now, for each 'diff' value, we need to make 'diff' times moves. Let's count that. 
        // Now assume that our selected element is the first, and our target is the third element.
        // We need to make the first element equal to the third one.
        int i = 0;
        int count = 0;
          
        while (i + 1 < nums.size()) { //target limit is last element
            int selected = i;
            int target = i + 1;
            int diff = nums[target] - nums[selected];

            // We have to increase all elements except the target by the diff
            for (int k = 0; k < nums.size(); k++) {
                if (k == target) continue;
                nums[k] = nums[k] + diff;
            }
            // Count total moves, i.e., diff = x, then we have to do x moves to increment the values (as per question conditions)
            count = count + diff;
            // Now change the target 
            i++;
        }

        return count;
    }
};


int main() {
    Solution solution;
    
    
    vector<int> nums = {1, 2, 3};
    int result = solution.minMoves(nums);

    cout << "Minimum moves to equalize the elements: " << result << endl;
    
    return 0;
}
