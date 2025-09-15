#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





bool check(vector<int>& nums) {
    int n = nums.size();
    int countPoint = 0;

    // If it's a normally sorted array, then all elements follow nums[i] <= nums[i+1].
    // But if it's a rotated sorted array, then there is exactly one point 
    // where nums[i] > nums[i+1]. This is the point where the original last 
    // element connects with the first element after rotation.
    
    /// Since the array is circularly rotated, we must check --
    // 1. Normal adjacent pairs: nums[i] > nums[i+1] for i in [0, n-2]
    // 2. The last and first element : nums[n-1] > nums[0] (using modulo to wrap around)
    for (int i = 0; i < n; i++) {
        // Circular check to find the drop point
        if (nums[i] > nums[(i + 1) % n]) { 
            countPoint++;
        }
        // If there is more than one drop point, it's not a valid rotated sorted array.
        if (countPoint > 1) return false;
    }
    
    return true;
}
int main(){

 
    vector<int>nums= {3,4,5,1,2};//1,2,3,4,5 -> rotation : 5,4,3,2,1 --> 4,5,1,2,3-->3,4,5,1,2
    bool ans = check(nums);
    cout<<ans;


}
  