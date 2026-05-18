#include<bits/stdc++.h>
using namespace std;

int calculate(int x, int y, char op){
    if(op == '+') return x + y;
    if(op == '-') return x - y;
    if(op == '*') return x * y;
    if(op == '/') return x / y;
    if(op == '^') return pow(x, y); // power
    return 0;
}

int postfixEvaluation(string s){
    stack<int> st;

    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }else{
            int y = st.top(); st.pop(); // right
            int x = st.top(); st.pop(); // left

            int res = calculate(x, y, s[i]);
            st.push(res);
        }
    }
    return st.top();
}

int main(){
    string postfix = "562*53+*+1+";
    int value = postfixEvaluation(postfix);
    cout << value << endl;
    return 0;
}