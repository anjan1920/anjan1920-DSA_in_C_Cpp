#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    // Push function for integer stack
    void push(int x, int stack[], int &top, int n) {
        if (top == n - 1) {
            // Stack Overflow
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            stack[top] = x;
        }
    }

    // Pop function for integer stack
    int pop(int stack[], int &top) {
        if (top == -1) {
            // Stack Underflow
            cout << "Stack Underflow!" << endl;
            return -1; // Return a sentinel value for error
        } else {
            int temp = stack[top];
            top--;
            return temp;
        }
    }

    // Function for precedence of operators
    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    // Function to check if the character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Function to check if the character is an operand (digit)
    bool isOperand(char c) {
        return isdigit(c);
    }

    string infixToPostfix(const string& str) {
    int n = str.length();
    int stack[n];
    string postfix = "";
    int topstack = -1;

    for (int i = 0; i < n; i++) {
        char c = str[i];

        if (isdigit(c)) {
            // Handle multi-digit numbers
            while (i < n && isdigit(str[i])) {
                postfix.push_back(str[i]);
                i++;
            }
            postfix.push_back(' '); // Use space to separate numbers
            i--; // Decrement i to adjust for the loop increment
        } else if (c == '(') {
            push(c, stack, topstack, n);
        } else if (c == ')') {
            while (topstack != -1 && stack[topstack] != '(') {
                postfix.push_back(pop(stack, topstack));
                postfix.push_back(' ');
            }
            pop(stack, topstack); // Pop the '(' from the stack
        } else if (isOperator(c)) {
            while (topstack != -1 && precedence(stack[topstack]) >= precedence(c)) {
                postfix.push_back(pop(stack, topstack));
                postfix.push_back(' ');
            }
            push(c, stack, topstack, n);
        }
    }

    while (topstack != -1) {
        postfix.push_back(pop(stack, topstack));
        postfix.push_back(' ');
    }

    cout << "Postfix: " << postfix << endl;
    return postfix;
}

   int evalPostfix(const string& str) {
    cout << "Received postfix in evaluate: " << str << endl;
    int n = str.size();
    int evalStack[n];
    int topeval = -1;

    for (int i = 0; i < n; i++) {
        char ch = str[i];

        if (isdigit(ch)) {
            // Handle multi-digit numbers
            int num = 0;
            while (i < n && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--; // Decrement i to adjust for the loop increment
            push(num, evalStack, topeval, n);
        } else if (isOperator(ch)) {
            int num2 = pop(evalStack, topeval);
            int num1 = pop(evalStack, topeval);
            int result = 0;

            switch (ch) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
                case '^': result = num1 ^ num2; break;
            }

            cout << "Result is " << result << " num1= " << num1 << " num2=" << num2 << endl;
            push(result, evalStack, topeval, n);
        }
    }

    return pop(evalStack, topeval);
}


    int calculate(const string& s) {
        // Convert infix to postfix
        string postfix = infixToPostfix(s);
        cout << "Received postfix in main: " << postfix << endl;

        // Evaluate the postfix expression to get the result
        int ans = evalPostfix(postfix);
        return ans;
    }
};

int main() {
    Solution sol;

    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);

    int result = sol.calculate(expression);
    cout << "The result of the expression is: " << result << endl;

    return 0;
}
