#include<iostream>
using namespace std;

// Push function for the stack
void push(char x, char stack[], int &top, int n) {
    // Check if the stack is full
    if (top == n - 1) {
        cout << "Stack Overflow!!" << endl;
    } else {
        top++; // move top pointer
        stack[top] = x; // push stack
    }
}

// Pop function for the stack
char pop(char stack[], int &top) {
    // Check if the stack is empty
    if (top == -1) {
        cout << "Stack Underflow!!" << endl;
        return '\0';
    } else {
        char temp = stack[top];
        top--; // decrement the top pointer
        return temp;
    }
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
//function to check if the c is operand or not
bool isOperand(char c) {
    // Check if the character is not an operator
    if (c != '/' && c != '*' && c != '(' && c != ')' && c != '+' && c != '-' && c != '^') {
        return true;
    } else {
        return false;
    }
}

// Function to convert infix to postfix
string infixToPostfix(string &str) {
    int n = str.length();
    char stack[n]; //stack for operator
    string postfix = ""; // stack to store  postfix expression
    int topstack = -1; // Top of operator stack

    //traverse the string of infix
    for (int i = 0; i < n; i++) {
        char c = str[i];
        // If the character is an operand, add it to the output
        if (isOperand(c)) {
            //c is ip
            postfix.push_back(c);
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(c, stack, topstack, n);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (topstack != -1 && stack[topstack] != '(') {
                char temp =pop(stack,topstack);
                postfix.push_back(temp);
            }
            pop(stack, topstack); // Pop the '(' from the stack
        }
        // If an operator 
        else if (isOperator(c)) {
            //push the the operator which have  precedence >= c to the postfix
            while (topstack != -1 && precedence(stack[topstack]) >= precedence(c)) {
                //pop to stack and push to postfix
                char temp =pop(stack, topstack);
                postfix.push_back(temp);
            }
            //push the final to stack
            push(c, stack, topstack, n);
        }
    }

    // Pop all the remaining operators from the stack
    while (topstack != -1) {
        char temp= pop(stack, topstack);
        postfix.push_back(temp);
    }

    //return the find posfix string
    return postfix;
}

int main() {
    string str = "14/3-2"; // fix expression
   string postfix = infixToPostfix(str); // Convert to postfix and print the result
   cout<<"Postfix expression :"<<postfix<<endl;
    return 0;
}
