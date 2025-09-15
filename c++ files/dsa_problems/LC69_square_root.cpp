#include<iostream>
#include<cmath>
using namespace std;

int main() {
    float x = 484;
    float s = 0;
    float e = x;
    float ans = -1;

    // Set precision limit
    float eps = 0.001;

    while ((e - s) > eps) {
        float mid = s + (e - s) / 2;
        float midSq = mid * mid;

        if (midSq == x) {
            ans = mid;
            break;
        }
        else if (midSq < x) {
            s = mid;
            ans = mid; // store last possible answer
        }
        else {
            ans = mid;
            e = mid;
        }
    }

    cout << "Square root of " << x << " =" << round(ans) << endl;
    return 0;
}
