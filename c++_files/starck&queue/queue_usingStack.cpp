#include <iostream>
#include <stack>
using namespace std;

class queue_usingSt {
    stack<int> s1;
    stack<int> s2;

public:
    // push (costly)
    void push(int n) {
        // step 1: move s1 -> s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // step 2: push new element
        s1.push(n);

        // step 3: move back s2 -> s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // pop
    void pop() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        int ele = s1.top();
        s1.pop();
        cout << "(" << ele << ") Popped\n";
    }

    // peek (front of queue)
    int peek() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s1.top();
    }

    // size
    int size() {
        return s1.size();
    }

    // display
    void display() {
        stack<int> temp = s1;
        cout << "FRONT -> ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "<- REAR\n";
    }
};

int main() {
    queue_usingSt q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();   // 10 20 30

    q.pop();
    q.display();   // 20 30

    cout << "Front: " << q.peek() << endl;
}