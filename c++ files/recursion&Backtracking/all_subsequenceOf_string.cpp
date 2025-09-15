#include<iostream>
#include<vector>
#include<string>

using namespace std;

void allSubseqString(string &s,string output, int i){
    //base case 

    if(i >= s.length()){
        //print and return
        cout<<output<<endl;
        return ;

    }

    //
    char ch = s[i];
    //include index content 
    allSubseqString(s,output,i+1);
    output.push_back(ch);
    allSubseqString(s,output,i+1);

    //exclude
    
    


}

int main(){
    string str = "abc";
    string output = "";
    allSubseqString(str,output,0);

    return 0 ;
}