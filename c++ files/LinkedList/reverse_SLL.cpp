#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(){
        this->next = NULL;
    }
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};


//function to print LinkedList
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        if(temp->next == NULL)cout<<"-->NULL";
        else cout<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}

//function to insert node at end
void insertAtEnd(Node* &head,int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = newNode;//if empty list then make head
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;//attach newNode at last
}
void  reverseSLL(Node* &head){
   Node *curr = head;
   Node* prev = NULL;
   Node* temp = head;
   while( curr != NULL){
        //temp store the curr node addr
        temp = temp->next;//move to next node
        curr->next = prev;//link direction changes
        prev = curr;
        curr = temp;//curr is the next node now
        
   }
   //at the end prev is new head
    head = prev;

    
}

int main(){
    //creating the sll
    vector<int>data;
    cout<<"Enter linked list elements:(Enter -1 to stop)";
    for(int i = 0 ;i>-1;i++){
        int ip ;
        cin>>ip;
        if(ip == -1){
            break;
        }else{
            data.push_back(ip);
        }
    }
    //create a SLL
    Node *head = NULL;
    for(int i = 0 ;i<data.size();i++){
        insertAtEnd(head,data[i]);

    }
    //print SLL
    printLL(head);
    reverseSLL(head);
    printLL(head);


}