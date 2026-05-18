#include<iostream>
#include<stack>
using namespace std;

// precedence
int priority(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return -1;
}


// infix -> postfix
string infix_toPostfix(string s){
    stack<char> st;
    string res;
    int i = 0;

    while(i < s.size()){
        char ch = s[i];

        // Operand
        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')){
            res += ch;
        }

        else if(ch == '('){
            st.push(ch);
        }

        else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        else{
            // operator
            while(!st.empty() && 
                 (priority(ch) < priority(st.top()) || 
                 (priority(ch) == priority(st.top()) && ch != '^'))){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }

        i++;
    }

    // pop remaining
    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}


int main(){
    string infix = "5+6*2*(5+3)+1^5";
    cout << infix_toPostfix(infix) << endl;
}