//1047
#include<iostream>
#include<string>
using namespace std;

void removeAdjacent(string &s){
    //
    string ans;
    int i = 0;
    while( i< s.length()){
      
        if(  ans.length() >0  && s[i] == ans[ans.length()-1]  ){
            //top character of ans = current character of s then remove it from ans 
            //when ans size is =0 then jump to else case
            ans.pop_back();


        }
        else{
            ans.push_back(s[i]);

        }
        i++;
    }
   // cout<<ans<<endl;
   //atlast swap the ans ans s
    s.swap(ans);
    

}

int main(){
    string str = "kollkatta";
    removeAdjacent(str);
    cout<<str;




}