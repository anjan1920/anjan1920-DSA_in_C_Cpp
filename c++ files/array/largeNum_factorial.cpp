//factorial of a Large number;
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//print array

void print(vector<int>&v){
for( int i=0 ;i< v.size() ;i++){
	cout<<v[i]<<" ";
	
}
cout<<endl<<"printing done--- "<<endl;

}

//function to find factorial of  a large number

vector < int > factLarge( int n){
    int carry=0;
    vector <int>ans;
    ans.push_back(1);

    for( int i=2 ;i<= n ; i++){

        for( int j= 0 ;j< ans.size(); j++){
            int x = ans[j]*i + carry;
            int rem = x%10;
            ans[j] = rem;
            carry = x/10;



        }
        //if carry present then push back it by digits
        while( carry > 0){
            ans.push_back( carry%10);
            carry = carry/10;

        }
        carry =0;

    }
 //now we get the array of ans but in reverse order
 reverse( ans.begin() , ans.end());

 return ans;





}

int main(){
    int n;
    cout<<"Enter a positive number:";
    cin>>n;

   
    vector<int> ans =  factLarge(n);

    print( ans);

    




return 0;

}
