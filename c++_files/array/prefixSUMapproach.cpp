#include<iostream>
#include<vector>
using namespace std;

vector<int> del_zeroConsecutive(vector<int>& v) {
    //Prefix sum approach
    // First make a map using vector
    cout<<"printing given vector:";
    for(auto num :v){
        cout<<num<<" ";
    }
    cout<<endl;
    vector<int> map(v.size(), 0);
    int psum = 0;
    for(int i = 0; i < v.size(); i++) {
        psum += v[i];
        map[i] = psum;
    }

    // Now perform operation on map
    for(int j = 0; j < map.size(); j++) {
        int data = map[j];
       // cout << "loop 1\n";
        // Now check if the data present on another index or not
        int sIndex = j + 1;
        int eIndex = -1;
        for(int k = sIndex; k < map.size(); k++) {
           // cout << "loop 2\n";
            if(data == map[k]) {
                eIndex = k;
                break; // Exit loop once end index is found
            }
        }
        if(eIndex != -1) {
            // The data map[j] also present in another index
            // Visit all the index from j+1 to that index 
            for(int t = sIndex; t <= eIndex; t++) {
               // cout << "loop 3\n";
                // Mark them as -> -1
                map[t] = -1;
            }
        }
        // If not then do nothing
    }
    cout<<"Printing Map:";
    for(auto num : map) {
        cout << num << " ";
    }
    //now create a vector from map index i = 0 to i = v.size()-1 skip those index value.
    //take index from map and values from v(given vector)
    vector<int>ans;
    for(int i = 0 ;i<map.size();i++){
        if(map[i]!=-1){
            ans.push_back(v[i]);

        }else{
            continue;
        }
    }
    return ans;
    
}

int main() {
    vector<int> input = {1,2,3,-3,4};
    vector<int>ans= del_zeroConsecutive(input);
    cout<<"printing final vector:";
    for (auto value :ans){
        cout<<value<<" ";
    }
}
