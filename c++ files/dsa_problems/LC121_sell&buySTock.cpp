#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    //brute force check for all the poir j,i i<j
        //Time complexity ~ O(n^2)
        /*
        int maxProfit = INT_MIN;

        for(int i = 0 ;i<prices.size() ;i++){
            int currentProfit = 0;

            for(int j =i+1 ;j<prices.size();j++){
                currentProfit = prices[j] - prices[i];

                if(currentProfit > maxProfit) maxProfit = currentProfit;



            }
        }


        return (maxProfit <0 )? 0 : maxProfit;
        */

        int byprice = prices[0]; //say first day is our buy price initially
        int profit = 0;

        for(int i =0 ;i<prices.size();i++){
            //check if we can get more low buy price or not
            int currentBuy_price = prices[i];
            if(byprice > currentBuy_price ){
                byprice = currentBuy_price ;

            }else{
                //if we can get a better profit 
                int currentprofit = currentBuy_price - byprice;
                if(currentprofit > profit){
                    profit = currentprofit;
                }
            }
        }


        cout<<"MAX profit:"<<profit;
        return 0;

    

}