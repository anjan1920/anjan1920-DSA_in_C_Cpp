#include<iostream>
#include<string>
using namespace std;

int checkPalindrome(string str){
    //it can handle both case when string is in word or in sentence
    string temp ;//empty string
    //copy all data of str in temp except space and make all character in capital
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
        }else{
            //convert small - caps;
            if( str[i]<='z' && str[i]>='a'){
                int capsAscii = (int)str[i] -32;
                char data = (char)capsAscii;
                temp.push_back(data);
                i++;
            }else{
                //when character is in caps
                temp.push_back(str[i]);
                i++;
            }


        }
    }
    //copy done now apply two pointer on temp string to check it is palindrome or not
    int l=0 ,r=temp.length()-1;
    //cout<<l<<","<<r<<endl;
    int flag =-1;
    //cout<<temp<<"**"<<endl;
    while( l <= r){
        if(temp[l]!= temp[r]){
            //not palindrome
            cout<<"Not palindrome."<<endl;
            flag =-1;
            return flag;
            
        }
        r++;
        l--;
    }
    cout<<"Palindrome"<<endl;
    return flag;
    //T.n =O(n){for copy} +O(n-num.of spaces){for palindrome checking} = O(n);

}
int main(){
    string str;
    cout<<"Enter string :";
    getline(cin,str);
    int ans=checkPalindrome(str);


}
