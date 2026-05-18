#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperand(char ch){
    if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')){
            return true;
    }
    return false;
}

string prefix_to_infix(string s){

    stack<string> st;

    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++){

        char ch = s[i];

        // operand
        if(isOperand(ch)){

            string temp = "";
            temp.push_back(ch);

            st.push(temp);
        }

        // operator
        else{

            string ele1 = st.top(); st.pop();
            string ele2 = st.top(); st.pop();

            string ele_new =  "("+ele1 + ch + ele2+")" ;

            st.push(ele_new);
        }
    }

    return st.top();
}

int main(){

    string prefix = "*+AB-CD";

    string ans = prefix_to_infix(prefix);

    cout << "Infix : " << ans << endl;

    return 0;
}