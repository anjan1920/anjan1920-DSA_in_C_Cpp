#include<iostream>
#include<vector>
#include<algorithm> // use to sort 
using namespace std;

void key_pair_twoPointer(vector<int> &arr){
    //we required sorted array increasing...order

    int n = arr.size();
    int x;
    cout<<"Enter target: ";
    cin>>x;


    vector<int>temp=arr; // T.N =O(log n)
    //sort function call
    sort(temp.begin() ,temp.end());

    int l = 0 , r = n-1 ;

    while( l < r  ){

        if ( temp[r] + temp[l] == x){

            cout<<"yes"<<endl;
            return ;

        }else if( temp[r] + temp[l] >x){
            //the target sum is < right and left index element so we have to 
            //decrease right ( r)  to minimize the sum value
            r--;


        }else{
             //the target sum is > right and left index element so we have to 
             //increase left (l)  to minimize the sum value

            l++;
        }
    }

    
 cout<<"no"<<endl;

//total T.N = O(n) + O(nlogn);

return ;

}

void key_pair(vector<int>&arr){
    int x;
    cout<<"Enter a number:";
    cin>>x;
    for( int i=0 ;i< arr.size(); i++){

        for(int j=i+1 ;j< arr.size() ;j++){

            if( arr[i] + arr[j] == x){
                cout<<"yes"<<endl;
                return ;
            }
        }
    }

    cout<<"No"<<endl;

}
int main(){

    vector<int>arr={10,20,30,2,1,1,};

    //key_pair(arr);

    key_pair_twoPointer(arr);




return 0;
}