#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findNth_ugly(int n) {
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return;
    }
   // vector to store the ugly number
    vector<int> ugly_list;
    ugly_list.push_back(1);

    int u1 = 2, u2 = 3, u3 = 5;
    int i1 = 0, i2 = 0, i3 = 0; // Indices for multiples of 2, 3, and 5

    while (ugly_list.size() < n) {
        int nextUgly1 = ugly_list[i1] * u1;
        int nextUgly2 = ugly_list[i2] * u2;
        int nextUgly3 = ugly_list[i3] * u3;
        //find the min among this ugly and push it to the vector
        int nextUgly = min({nextUgly1, nextUgly2, nextUgly3});

        ugly_list.push_back(nextUgly);

        //if pushed ugly is same as any of the nextugly then move the pointer to  that ugly number
        //so that the previous calculated ugly which is not pushed in the vector will be calculated again
        if (nextUgly == nextUgly1) i1++;
        if (nextUgly == nextUgly2) i2++;
        if (nextUgly == nextUgly3) i3++;
    }
   
    for (int i = 0; i < ugly_list.size(); i++) {
        cout << ugly_list[i] << " ";
    }
    cout << endl;
}

int main() {
    findNth_ugly(10);
    return 0;
}
