//return the indexes i,j of the subarray where the  sum = given value in range i-j
//this is not a good approach when sum value is too high because T.n = O(n^2rr)

#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    vector<int> temp;
    int k = 0;
    while (k <= arr.size() - 1)
    {
        int sum = 0;
        for (int i = k; i <= arr.size() - 1; i++)
        {
            sum = sum + arr[i];
            if (sum == s)
            {
                temp.push_back(k + 1);
                temp.push_back(i + 1);
                return temp;
            }
        }
        k++;
    }
    temp.push_back(-1);
    return temp;
}

int main()
{
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    long long targetSum = 15;

    vector<int> result = subarraySum(arr, n, targetSum);

    // Displaying the result
    if (result[0] == -1)
    {
        cout << "No subarray found with the given sum." << endl;
    }
    else
    {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << "." << endl;
    }

    return 0;
}

