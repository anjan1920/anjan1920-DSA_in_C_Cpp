//we use vector to create a map and then we check if element is already visited or not.s

//if yes then it is duplicate
//T.n =o(n){traversing the array}+ o(nlogn){sort function}= O(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(long long arr[], int n) {
    vector<int> map(n, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int index = arr[i];
        if (map[index] == 0) {//0->not visited
            map[index] += 1;// value of the index 0->1
        } else if (map[index] == 1) {//visited once
            ans.push_back(arr[i]);
            map[index] += 1;//1->2
        }
        //when index value is 2 then its visited 2 times dont need to push back to ans vector
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        ans.push_back(-1);
    }

    return ans;

    
}

int main() {
    
    int n = 8;
    long long arr[] = {3, 2, 4, 3, 5, 2, 6, 1};

    vector<int> result = findDuplicates(arr, n);

    cout << "Duplicate elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
