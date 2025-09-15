#include<iostream>
using namespace std;



bool checkPalindrome(string &str,int s,int e){
    //base case
    if(s>=e){
        return true;
    }
    //check
    if(str[s]==str[e]){
        //may be its palindrome check further
        return checkPalindrome(str,s+1,e-1);

    }else{
        //not palindrome 
        return false;
    }

    

    

}
int main(){
    string str="madam";
    bool ans= checkPalindrome(str,0,str.length()-1);
    cout<<ans;
    

}