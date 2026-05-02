#include<iostream>
using namespace std;
    int getLucky(string s, int k) {
        // Step 1: Convert the string to a numeric string
        string numStr;
        for (int i = 0 ;i<s.length();i++) {
            int value = s[i] - 'a' + 1;//i.e a-a+1=1
            numStr =numStr+to_string(value);//Returns a string with the representation of value.
        }
        
        // Step 2: Perform the sum operation upto k times
       int sum = 0;
        while (k!=0) {
            sum = 0;
            for (int i = 0 ;i<numStr.length();i++) {
                sum = sum + numStr[i] - '0'; // Convert character digit to integer and add to sum
            }
            numStr = to_string(sum); // re assign the string with sum 
            k--;
        }
        
        // Step 3: Return the final result
        return sum;
    }
int main(){
    string s="anjan das";
    int ans =getLucky(s,2);
    cout<<ans<<endl;

}

