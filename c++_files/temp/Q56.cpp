#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator function to sort by the first element of the interval
bool compareByFirstElement(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

   /*Step 1: Sort the 2D vector by the starting interval.
    Step 2: Initialize a new 2D vector and add the first interval from the sorted vector.
    Step 3: Iterate through the sorted intervals:
    - Compare the ending interval of the last added interval with the starting interval of the current interval.
    - If there is an overlap (i.e., the ending interval is greater than or equal to the starting interval):
        - Merge the intervals by updating the ending interval.
    - If there is no overlap:
        - Push the current interval into the new vector.
    Step 4: Return the merged intervals.*/

    // Sort the intervals by their starting values
    sort(intervals.begin(), intervals.end(), compareByFirstElement);

    vector<vector<int>> ans;

    // Add the first interval to the result
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // Get the last interval of the ans in a 1D vector
        vector<int> lastInterval = ans.back();

        // Check for overlap
        if (lastInterval[1] >= intervals[i][0]) {
            // Merge them
            lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            // Update the ans
            ans.back() = lastInterval;
        } else {
            // No overlap, add the current interval to the result
            ans.push_back(intervals[i]);
        }
    }

    // Return the merged intervals
    return ans;

    //time complexity = O(nlogn){sorting} +O(n) {for traversing the 2d array} =O(nlogn)
}

int main() {
    // Example intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Call mergeIntervals function
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    // Output the merged intervals
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
