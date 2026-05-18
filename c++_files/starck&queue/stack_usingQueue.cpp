#include <iostream>
#include <queue>
using namespace std;

class st_usingQ {
    queue<int> q1;
    queue<int> q2;

public:
    // push
    void push(int n) {
        // step 1: push new element into q2
        q2.push(n);

        // step 2: move all elements from q1 to q2
        while (!q1.empty()) {
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
        }

        // step 3: swap q1 and q2
        swap(q1, q2);
    }

    // pop
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    // top
    int peek() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // size
    int size() {
        return q1.size();
    }

    // display 
    void display() {
        //make a copy
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    //create obj
    st_usingQ s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); 

    cout << "Top: " << s.peek() << endl;

    s.pop();
    s.display();  // 20 10
}