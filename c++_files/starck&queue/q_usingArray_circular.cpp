#include<iostream>
using namespace std;

//circular queue

class q_usingArray{
    int size = 10;
    int q[10];  // FIXED
    int currSize = 0;
    int st = -1;
    int end = -1;

public:
    //push
    void push(int x){
        if(currSize == size){
            //overflow
            cout<<"Overflow!!"<<endl;
            return;
        }

        if(currSize == 0){
            st = 0;
            end = 0;
        }else{
            end = (end + 1) % size;
        }

        q[end] = x;
        currSize++;
    }

    //pop
    void pop(){
        if(currSize == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }

        int ele = q[st];  

        if(currSize == 1){
            st = -1;
            end = -1;
        }else{
            st = (st + 1) % size;
        }

        currSize--;
        cout<<"Popped: "<<ele<<endl;
    }

    //top (front)
    int peek(){
        if(currSize == 0){
            cout<<"Queue empty"<<endl;
            return -1;
        }
        return q[st];  
    }

    int getSize(){
        return currSize;
    }

    void display(){
        if(currSize == 0){
            cout<<"Queue empty"<<endl;
            return;
        }

        cout<<"Queue: ";
        int i = st;
        for(int cnt = 0; cnt < currSize; cnt++){
            cout<<q[i]<<" | ";
            i = (i + 1) % size;
        }
        cout<<endl;
    }
};

int main(){
    q_usingArray q;
    int choice, value;

    do{
        cout<<"\n--- QUEUE MENU ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Size\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                q.push(value);
                break;

            case 2:
                q.pop();
                break;

            case 3:
                cout<<"Front element: "<<q.peek()<<endl;
                break;

            case 4:
                cout<<"Current size: "<<q.getSize()<<endl;
                break;

            case 5:
                q.display();
                break;

            case 6:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice != 6);

    return 0;
}