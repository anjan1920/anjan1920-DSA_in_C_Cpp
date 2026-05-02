#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
    
vector<int> getFloorAndCeil(int x, vector<int>& arr) {
            int celi = -1;
            int flor = -1;
    
            sort(arr.begin(), arr.end());
    
            // Floor of x is the largest element which is smaller than or equal to x
            if (x < arr[0] && x > arr[arr.size() - 1]) return {-1,-1};
            
            
            
    
            // Binary search for ceil
            int s = 0, e = arr.size() - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (arr[mid] >= x) {
                    celi = arr[mid];
                    e = mid - 1;  // Move left to find a smaller ceiling
                } else {
                    s = mid + 1;
                }
            }
    
            // Binary search for floor
            s = 0, e = arr.size() - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (arr[mid] <= x) {
                    flor = arr[mid];
                    s = mid + 1;  // Move right to find a larger floor
                } else {
                    e = mid - 1;
                }
            }
    
    return {flor, celi};
}

int main(){
    vector<int>nums = {54,1,0,6,8,1,8,51};
    int num = 5;
    vector<int>ans = getFloorAndCeil(num,nums);
    cout<<ans[0]<<" ,"<<ans[1];
    return 0;

}
   