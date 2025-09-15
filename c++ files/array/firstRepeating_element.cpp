//First repeating element
//return the low index of the repeating element
//index start from 1 not 0

#include<iostream>
#include<vector>

using namespace std;


int main() {
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    int n = arr.size();
    int ans = -1;

    for (int i = 0; i < n; i++) {
       

        for (int j = i + 1; j < n; j++) {
            

            if (arr[i] == arr[j]) {
                // Duplicate of i found.
                // Return the first occurrence.
                ans = i;
                break;
            }
        }

        if (ans != -1) {
            // If a repeating element is found, break out of the outer loop.
            break;
        }
    }

    if (ans != -1) {
        // Adding 1 because the  index starts from 1.
        ans += 1;
    }

    cout << ans << endl;
}
//T.N =O(n2);
//when the i/p is so large then its take too much amount of time " not a perfect solution"