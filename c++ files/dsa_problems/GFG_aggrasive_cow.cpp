#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool can_place_cow(int min_dis,vector<int>&stalls,int k){
        //place the cow from the 0 
        int last_placed_cow = stalls[0];
        int cow_count = 1;//every place of cow count the cow
        for(int i = 1 ;i<stalls.size();i++){
            int dis = stalls[i]-last_placed_cow;
            if(dis >= min_dis){
                cow_count++;
                last_placed_cow = stalls[i];
            }else{
                //cant place this cow here
                continue;
            }
            if(cow_count >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int mn = stalls[0];
        int mx = stalls[stalls.size()-1];
        int max_dis = 0;
        int s  = 1 ;
        int e = mx-mn;
        while(s <=e ){
            int mid = s + (e-s)/2;
            int min_dis_threshold = mid;
            if(can_place_cow(min_dis_threshold,stalls,k)){
                //yes then continue
                max_dis = mid;
                continue;
            }else{
                //just prev threshold is the max_dis
                max_dis = mid- 1;
                break;
            }
        }
        return max_dis;
    }
};

int main(){
    vector<int>stalls = {2,3,4,7,11};
    int k = 5;
    Solution* obj;
    int ans = obj->aggressiveCows(stalls,k);
    cout<<ans<<endl;
    return 0;
}