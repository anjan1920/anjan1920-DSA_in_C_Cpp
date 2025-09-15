#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){



    /*vector<int>arr = {1,9,2,5,3,6};
    int k =  10;

    //Longest Subarray with Sum K 
    //IF there are no -ve value then we can apply dynamic sliding window approach
    int maxWin_size = INT_MIN;
    int sum =  0;
    int r = 0 ;
    int  l = 0;
    while( r < arr.size()){
        sum+=arr[r];

        if(sum == k){
            //save the window size
            maxWin_size = max(maxWin_size,r - l +1);
        }

        //if size > k ,,have to shrink
        while( sum > k){

            //remove the previous once 
            sum = sum - arr[l];
            //shrink
            l++;
        }

        //expand
        r++;

    }

    cout<<"Max size of subarray with sum ="<<k<<" is :"<<maxWin_size;
    */

    //if there are negative value then after adding element the sum get reduce 
    //then its impossible to do shrink or expand decision

  // Using Prefix Sum and Hash Map Approach

    // We traverse the array while maintaining a prefix sum and store it in a map.
    // The map stores key-value pairs in the format: (prefix sum → index).
    // Example: At index = 2, if the prefix sum is (10 + 5 + 2) = 17,
    //          we store it as map[17] = 2.

    // Now, at any index 'i', we check:
    // - If `currentSum == k`, it means we found a subarray from index 0 to i with sum k.
    // - If `(currentSum - k)` exists in the map, it means there is a previous subarray
    //   whose sum is `(currentSum - k)`, and the remaining subarray (after that index)
    //   must have sum `k`.

    // The key in the map represents the index of that prefix sum.
    // So, the valid subarray with sum `k` starts from (key + 1) to the current index 'i'.
    // The length of this subarray is calculated as: `i - (map[currentSum - k])`.



    // Create an unordered_map
    vector<int>arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    unordered_map<int, int> myMap;
    int maxWin = INT_MIN;
    int currentSum = 0;
    bool flag =false;
    
    int i = 0;
    
    while (i < arr.size()) {
        currentSum += arr[i];
    
        if (currentSum == k) {
            //save the size of the sub array
            int winSize = i + 1; 
            maxWin = max(winSize, maxWin);
            flag = true;
        }
        
        //if the the map contains the currentSUm - k i.e the prefix sum
        
        if (myMap.find(currentSum - k) != myMap.end()) { 
        // myMap.end() returns an 
        //iterator that points to the position after the last element in the myMap i.e invalid 
    
            //then a sub array is present with sum k
            int startIndex = myMap[currentSum - k] + 1;  
            int endIndex = i; 
            int winSize = endIndex - startIndex + 1;  
            maxWin = max(winSize, maxWin);
            flag = true;
        }
    
        //  currentSum is not exists then add 
        if (myMap.find(currentSum) == myMap.end()) {
            myMap[currentSum] = i;
        }
    
        i++;  
    }
    
    (flag) ? cout<<maxWin :cout<< 0;



}