/*At a lemonade stand, each lemonade costs $5.
 Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
 Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
 You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays,
 return true if you can provide every customer with the correct change, or false otherwise.*/

#include<iostream>
#include<vector>
using namespace std;

    bool lemonadeChange(vector<int>& bills) {
        int fund[3] = {0, 0, 0}; // fund[0] -> $5 notes, fund[1] -> $10 notes, fund[2] -> $20 notes
        
        for (int i = 0; i < bills.size(); ++i) {
            int bill = bills[i];
            int return_amount = bill - 5;

            if (return_amount == 0) {
                // Customer pays with $5 note
                fund[0]++;
            } else if (return_amount == 5) {
                // Customer pays with $10 note
                if (fund[0] > 0) {
                    fund[0]--; // Use one $5 note
                    fund[1]++; // Increase $10 notes count
                } else {
                    return false; // Cannot give $5 change
                }
            } else if (return_amount == 15) {
                // Customer pays with $20 note
                if (fund[1] > 0 && fund[0] > 0) {
                    fund[1]--; // Use one $10 note
                    fund[0]--; // Use one $5 note
                    fund[2]++;
                } else if (fund[0] >= 3) {
                    fund[0] -= 3; // Use three $5 notes
                     fund[2]++;
                } else {
                    return false; // Cannot give $15 change
                }
                
            }
        }
        return true;
        //time complexity =O(n)
    }
int main()
{
        vector<int>bills={5,5,10,20,5};
        bool ans =lemonadeChange(bills);
        if(ans){
            cout<<"Yes we can provide changes to all customers ."<<endl;
        }else{
             cout<<"Yes we can't provide changes to all customers ."<<endl;

        }
        return 0;
}
