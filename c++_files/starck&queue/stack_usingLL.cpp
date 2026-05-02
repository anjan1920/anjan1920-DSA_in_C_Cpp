#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class st_usingLL{
    Node* top = NULL;
    int size = 0;
public:
    //push
    void push(int x){
        //crate new node
        Node* temp = new Node(x);
        //connect the node with top node
        temp->next = top;   // FIXED
        //move top 
        top = temp;
        size++;
    }

    void pop(){
        if( top == NULL){
            cout<<"Stack is empty!!"<<endl;
            return ;
        }else{
            Node* temp = top;
            int ele = temp ->data;
            //move top
            top = top->next;
            delete temp;
            size--;
            cout<<"("<<ele<<")"<<" Popped"<<endl;
        }
    }

    //top
    int peek(){
        if(top == NULL){
            cout<<"Empty stack !!"<<endl;
            return -1;
        }else{
            return top->data;
        }
    }

    //display
    void show(){
        Node* temp = top;
        cout<<"Top --> Bottom : ";
        while (temp != NULL)
        {
            cout<<temp->data<<" | ";
            temp = temp ->next;
        }
        cout<<endl;
    }
};

int main(){
    st_usingLL s;
    int choice, value;

    do{
        cout<<"\n--- STACK (Linked List) MENU ---\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout<<"Top element: "<<s.peek()<<endl;
                break;

            case 4:
                s.show();
                break;

            case 5:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice != 5);

    return 0;
}