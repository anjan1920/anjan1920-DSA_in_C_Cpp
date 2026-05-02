

#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
            vector<int>ans;
            ans.push_back(nums[0]);
    
            int i = 1;
            while(i < nums.size()){
    
                if(nums[i] == ans[ans.size()-1]){
                    //then its duplicate move the pointer
                    i++;
                }else{
                    ans.push_back(nums[i]);
                }
            }
    
            nums = ans;
            return ans.size();
            
}

int main(){
    vector<int>nums = {1,2,2,2,3,4,5,5,5,5,6,7,7,8};
    int ans = removeDuplicates(nums);
    cout<<"Duplicates :"<<ans<<endl;
    //final array
    cout<<"Final array :";
    for(auto val : nums){
        cout<<val<<",";
    }

    return 0;
}
   