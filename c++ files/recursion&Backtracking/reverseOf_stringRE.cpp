#include<iostream>
using namespace std;

//reverse of string using recursion

void rev(string &str,int s,int e){

    //base case
    if(s>=e ){
        return;
    }
    //else perform swapping of last index to the first index 
    swap(str[s],str[e]);
    //recursive call
    rev(str,s+1,e-1);



}
int main(){
    string str="anjan das";
    cout<<"original string:"<<str<<endl;
    int s=0,e=str.length()-1;
    rev(str,s,e);
    cout<<"Modified string:"<<str<<endl;

}