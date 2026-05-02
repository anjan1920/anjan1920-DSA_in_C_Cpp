#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class q_usingLL{
    Node* st;
    Node* end;
    int size = 0;

public:
    // constructor to initialize pointers
    q_usingLL(){
        st = NULL;
        end = NULL;
    }

   //push
   void push(int x){
        Node* temp = new Node(x);
        if(st == NULL){
            st = end = temp;
        }else{
            end->next = temp;
            end = temp;
        }
        size+=1;
   }

   //pop
   void pop(){
        if(st == NULL){
            cout<<"Queue is empty!!"<<endl;
            return;
        }

        Node* temp = st;
        int ele = temp->data;

        st = st->next;
        if(st == NULL) end = NULL; 

        delete temp;
        size--;

        cout<<"Popped: "<<ele<<endl;
   }

   //peek (front)
   int peek(){
        if(st == NULL){
            cout<<"Queue empty!!"<<endl;
            return -1;
        }
        return st->data;
   }

   //display
   void show(){
        if(st == NULL){
            cout<<"Queue empty!!"<<endl;
            return;
        }

        Node* temp = st;
        cout<<"Front --> ";
        while(temp != NULL){
            cout<<temp->data<<" | ";
            temp = temp->next;
        }
        cout<<" <-- Rear"<<endl;
   }

   int getSize(){
        return size;
   }
};

int main(){
    q_usingLL q;
    int choice, value;

    do{
        cout<<"\n--- QUEUE (Linked List) MENU ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Size\n";
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
                q.show();
                break;

            case 5:
                cout<<"Current size: "<<q.getSize()<<endl;
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