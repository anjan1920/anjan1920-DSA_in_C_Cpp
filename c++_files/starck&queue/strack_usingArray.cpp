#include <iostream>
using namespace std;

class st_usingArray {
    int st[10];
    int top = -1;

public:
    // push
    void push(int x) {
        if (top >= 9) {
            cout << "Stack overflow !!" << endl;
            return;
        }
        top++;
        st[top] = x;
    }

    // pop
    void pop() {
        if (top == -1) {
            cout << "Stack underflow!!" << endl;
            return;
        }
        cout << st[top] << " popped" << endl;
        top--;
    }

    // peek
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
            return -1;
        }
        return st[top];
    }

    // display
    void showST() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << st[i] << " | ";
        }
        cout << endl;
    }
};

int main() {
    st_usingArray s;
    int choice, value;

    while(true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            cout << "Top element: " << s.peek() << endl;
            break;

        case 4:
            s.showST();
            break;

        case 5:
            cout << "Exiting..." << endl;
            return false;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } 

    return 0;
}