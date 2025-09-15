//shift zero to last while maintaining the relative order of non zero element

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


    void moveZeroes(vector<int>& nums) {
        int i = 0, j = i + 1;
        //simpe approach traverse the array and maintain this bellow three condition

        while (i < nums.size() && j< nums.size())  {
            //when data at i is not zero then no need to any changes
            if (nums[i] != 0 && j < nums.size()) {
                i++;
                j++;
            } else if (nums[i] == 0 && nums[j] != 0) {
                //data at i is zero and data at j non zero so swap them and move i ->i+1
                swap(nums[i], nums[j]);
                i++;
            } else {
                //when both data of i and j is zero only move j untill its find a non zero data then its swap to i position 
                j++;
            }
        }
    }

    int min(){


    }