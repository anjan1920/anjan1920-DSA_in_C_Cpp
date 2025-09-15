#include<iostream>
#include<vector>
using namespace std;
//find misssing number in  1-n;
 int missingNumber(vector<int>& nums) {

        int n=nums.size();
        int sum_arr=0;
//find the sum of the given array
        for(int i=0 ;i<n ;i++ ){

            sum_arr = sum_arr  + nums[i];
        }
        //calculate sum of 1-n  by using ap formula  
        int a=1 ,l=n;
        int sum= n*(( a + l ))/2;
        //return the difference 
        return sum-sum_arr;
        
    }
int main(){

    vector<int >nums={0, 1 ,2 , 3 ,4};
    int ans = missingNumber(nums);

    cout<<"misiing number in th range of "<<1<<" "<< nums.size()<< "Is :"<<ans<<endl;


   

 return 0;
}
