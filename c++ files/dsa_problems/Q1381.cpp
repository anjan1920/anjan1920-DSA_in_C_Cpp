#include <iostream>
#include <algorithm>  

using namespace std;

class CustomStack {
private:
    int* stack;  // Pointer to dynamic array
    int top;     
    int maxSize; 

public:
    // Constructor to initialize the stack with a given max size
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        top = -1;
        stack = new int[maxSize]; 
    }

    // Destructor to free the dynamically allocated memory
    ~CustomStack() {
        delete[] stack;
    }

    
    void push(int x) {
        if (top == maxSize - 1) {
            // Stack overflow
            return;
        }
        top++;
        stack[top] = x;
    }

  
    int pop() {
        if (top == -1) {
            // Stack is empty, return -1
            return -1;
        }
        int result = stack[top];
        top--;
        return result;
    }

    void increment(int k, int val) {
        // If the number of elements in the stack is less than k, increment all elements
        int limit = min(k, top + 1);  // `top + 1` is the current size of the stack
        for (int i = 0; i < limit; i++) {
            stack[i] += val;
        }
    }
};


int main() {
    // Create a stack with a maximum size of 5
    CustomStack* customStack = new CustomStack(5);

    // Push elements 
    customStack->push(1);
    customStack->push(2);
    customStack->push(3);

    // Pop an element & display it
    cout << "Popped: " << customStack->pop() << endl;  // Should output 3

    // Push 
    customStack->push(4);
    customStack->push(5);
    customStack->push(6);

    // Increment the bottom 2 elements by 10
    customStack->increment(2, 10);

    // Pop and display elements
    cout << "Popped: " << customStack->pop() << endl;  // Should output 6
    cout << "Popped: " << customStack->pop() << endl;  // Should output 15 (5 + 10)
    cout << "Popped: " << customStack->pop() << endl;  // Should output 14 (4 + 10)
    cout << "Popped: " << customStack->pop() << endl;  // Should output 1

    // Clean up
    delete customStack;

    return 0;
}
