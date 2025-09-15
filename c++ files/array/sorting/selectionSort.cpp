// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//function to display array
void show_array(vector<int>&arr, int n){
    int i = 0;
    while(i < n){
        cout << arr[i];
        if(i != n - 1){
            cout << ",";
        }
        i++;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 4, 3, 0, 1};
    int n = arr.size();

    // selection sort

    // we start from start or end of the array
    // this will be our start point of unsorted portion
    // then select the min or max element in the unsorted region
    // say we select the min
    // then we place it to the start and move the pointer i
    //unsorted portion starting pointer

    int start = 0;
    int end = n;
    int min = INT_MAX;
    int min_index;
    while(start < end){
        // now find min element in start to end region
        for(int j = start; j < end; j++){
            if(arr[j] < min){
                min = arr[j];
                min_index = j;
            }
        }

        // here we get the most min element in start to end region
        // now place it to the starting of the unsorted region by swapping
        swap(arr[min_index],arr[start]);

        // move the starting pointer (shrink the unsorted region from the left)
        start++;
        //reset the min
        min = INT_MAX;

        // display the array after each pass
        show_array(arr, n);
    }

    return 0;
}
