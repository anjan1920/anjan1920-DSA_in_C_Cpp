

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int calculate_eatingTime(int k,vector<int>&piles,int h){
        // If piles[i] has 10 bananas
        // and speed k = 10 or k >= 10, then Koko takes only 1 hour to eat that pile.
        // (i.e. hours = hours + 1)

        // If piles[i] > k, e.g., piles[i] = 25 and speed = 10,
        // Koko needs: 10 (1hr) + 10 (1hr) + 5 (1hr) => total 3 hours.
        // That is: 25 / 10 = 2, and because 25 % 10 != 0, we add 1 extra hour.

        // Example: if piles[i] = 30 --> 30 / 10 = 3 and 30 % 10 == 0,
        // so total hours = 3.

        long hr_need = 0;
        for(int i = 0 ;i<piles.size();i++){
            if(piles[i] < k) 
                hr_need++;  // can finish in 1 hour
            else{
                long digit = piles[i] / k;  // hours for full chunks
                long rem = piles[i] % k;   // remaining bananas
                long time = digit;
                if(rem != 0) time += 1;    // need 1 more hour if remainder exists

                hr_need += time;           
            }
            if(hr_need > h) return h + 10; 
        }
        return hr_need;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Koko needs to eat all bananas in h hours.
        // We want to find the minimum integer k bananas/hour that allows this.
        // The maximum possible speed is the maximum value in piles.
        // The minimum possible speed is 1.

        sort(piles.begin(),piles.end());
        int s  = 1;
        int ans  = -1;
        int e = piles[piles.size()-1];
        while( s <= e){
            int mid = s + (e - s)/2;  
            int k = mid;
            // Calculate time needed with current speed k
            int time_need = calculate_eatingTime(k,piles,h);
            if(time_need <= h){
                // Koko can eat all bananas within h hours at speed k
                ans = k;
                // Try reduce speed speed
                e = mid - 1;
            }
            else{
                // Koko needs more speed
                s = mid + 1;
            }
        } 
        return ans;
    }
};


int main() {
    Solution obj;

    vector<int> arr = {3,6,7,100,1,1,1,1,1};
    int h = 10;
    int ans = obj.minEatingSpeed(arr, h);
    cout << "Minimum eating speed: " << ans << endl;

    return 0;
}
