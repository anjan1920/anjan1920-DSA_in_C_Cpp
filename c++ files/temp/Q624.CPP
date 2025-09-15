/*You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and
calculate the distance. We define the distance between two integers a and b to be their
absolute difference |a - b|.Return the maximum distance.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>


using namespace std;

int maxDistance(vector<vector<int>>& arrays) {


   /* At the end, there are two possible case:
    1. The overall minimum and maximum are in different sub-arrays. 
    In this case, return the difference between the max and min values.
    2. The overall minimum and maximum are in the same sub-array (let's say the i-th sub-array).
    In this case, we need to find another pair of max and min values from the remaining sub-arrays (excluding the i-th sub-array).
    Let's say we find these values in the j-th sub-array. Then we have two possible results:
    - ans1 = max(i-th sub-array) - min(j-th sub-array)
    - ans2 = max(j-th sub-array) - min(i-th sub-array)
    Return the more optimal difference.*/
    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    int maxVal_index = -1;
    int minVal_index = -1;

    // Let's find the overall max and min in the 2d array
    for(int i = 0 ; i < arrays.size() ; i++ ){
        if(arrays[i].back() > maxVal) {
            // Update the max value
            maxVal = arrays[i].back();
            maxVal_index = i;
        }
        if(arrays[i][0] < minVal) {
            // Update the min value
            minVal = arrays[i][0];
            minVal_index = i;
        }
    }

    // We found the min and max globally

    if( maxVal_index == minVal_index ){
        // Both min_val and max_val found in same sub array 
        // Let's find another min and max except the previous subarray
        int maxVal2 = INT_MIN;
        int minVal2 = INT_MAX;

        for(int i = 0 ; i < arrays.size() ; i++ ){
            if(i == maxVal_index ){
                // Ignore the sub array i.e row
                continue;
            }
            if(arrays[i].back() > maxVal2) {
                // Update the max value
                maxVal2 = arrays[i].back();
            }
            if(arrays[i][0] < minVal2) {
                // Update the min value
                minVal2 = arrays[i][0];
            }
        }

        return max(maxVal - minVal2, maxVal2 - minVal);
    } else {
        return maxVal - minVal;
    }
}

int main() {
    vector<vector<int>> arrays = {{-6,-3,-1,1,2,2,2},{-10,-8,-6,-2,4},{-2},{-8,-6,-5,-4,-2,-2,2,4}};
    cout << "Maximum distance is: " << maxDistance(arrays) << endl;
    return 0;
}