 #include<iostream>
 #include<vector>
 #include<unordered_map>
 #include<algorithm>
 using namespace std;

 int main(){
 
 /*
        //Naive approach 
        //for every index find the another index where nums[i] + nums[j]  == target
        //T.n ~ O(n^2);

        int i = 0;
        int j;
        while(i < nums.size()){

             j = i + 1;
             while(j  <nums.size()){
                if(nums[i] + nums[j] ==  target){
                    return {i,j};
                }
                j++;
             }
             i++;
        }

        return {-1,-1};
        
    }*/

    //using hashmap O(n)

    vector<int>nums = {2,7,11,15};
    int target = 9;

    unordered_map<int, int> myMap;
    //

    for(int i = 0 ;i<nums.size();i++){

       int complement = target - nums[i];

       if(myMap.find( complement)!= myMap.end()){
           cout<<myMap[complement]<<","<<i<<endl; 
           break;
       }
       //if not present 
       //add on the hash map
       myMap[nums[i]] = i ;// key is nums[i]  ->value , valu is index -->i


    }


    

return 0;
 
}