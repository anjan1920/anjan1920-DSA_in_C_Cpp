#include<iostream>
#include<string>

using namespace std;

// Leetcode 1047 - Problem Statement: Remove All Adjacent Duplicates In String
// Given a string s, remove all adjacent duplicates in the string repeatedly until no duplicates remain.
// Return the final string after all such duplicate removals.

//using stack approach
//we push one by one character rom the end of the string
//and if the stack is not empty and the top of the stack is same as the current
//then we pop the top of the stack
string removeDuplicates(string s) {
    string stack = "";
    for(char ch : s){
        //if stack is not empty & push item == top
        if(!stack.empty() && stack.back() == ch){
            //then pop
            stack.pop_back();
        }else{
            //push on top
            stack.push_back(ch);
        }
    }
    return stack;
}


int main() {
    string s = "abbaca";
    string result = removeDuplicates(s);
    cout << "Result: " << result << endl;

   return 0;
}
