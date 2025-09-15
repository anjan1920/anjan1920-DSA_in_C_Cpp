// Online C++ compiler to run C++ program online
#include <iostream>
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

//utility function to calculate linkedlist size
int calLinkedList_size(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

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

//function to insert node at beginning
void insertAtBeg(Node* &head,int value){
    Node* newNode = new Node(value);
    newNode->next = head;//link newNode to head
    head = newNode;//make newNode as head
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

//function to insert node at given position
void insertAtPosi(Node* &head,int posi,int value){
    int size = calLinkedList_size(head);
    if(posi < 1 || posi > size+1){
        cout<<"LinkedList size :"<<size<<", Given position:"<<posi<<". Can't Insert outofbound!!"<<endl;
        return;
    }else if(posi == 1) insertAtBeg(head,value);
    else if(posi == size+1) insertAtEnd(head,value);
    else{
        //insert in btw
        Node* newNode = new Node(value);
        Node* temp = head;
        int curr_posi = 1;
        while(curr_posi < posi-1){
            temp = temp->next;
            curr_posi++;
        }
        //now temp is position-1 node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//function to delete first node
void delFirstNode(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        cout<<"Can't Delete Empty LinkedList !!"<<endl;
        return ;
    }
    head = temp->next;//move head to next node
    temp->next = NULL;//break the link 
    delete temp;//free memeory
}

//function to delete last node
void delLastNode(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        cout<<"Can't Delete Empty LinkedList !!"<<endl;
        return ;
    }
    //move to the 2nd last node
    Node* prevNode = NULL;
    while(temp->next != NULL ){
        prevNode = temp;
        temp = temp->next;
    }
    //prevNode is 2nd last  node
    if(prevNode != NULL){
        prevNode->next = NULL;//break the link
    }else{
        head = NULL;//if only 1 node
    }
    delete temp;//free memory
}

//function to delete any position node
void deleteAnyPosi(Node* &head,int posi){
    int size = calLinkedList_size(head);
    if(posi < 1 || posi > size){
        //cant possible to delete
        cout<<"LinkedList size :"<<size<<", Given position:"<<posi<<". Can't Delete outofbound!!"<<endl;
        return ;
    }else if(posi == 1) delFirstNode(head);
    else if(posi == size) delLastNode(head);
    else{
        //delete in btw
        Node* prevNode = NULL;
        Node* temp = head;
        int curr_posi = 1;
        while(curr_posi < posi){
            prevNode = temp;
            temp = temp->next;
            curr_posi++;
        }
        //now temp is position node
        prevNode->next = temp->next;//skip temp node
        temp->next = NULL;//isolate temp
        delete temp;//free memory
    }
}


int main(){
    Node* head = NULL;
    int choice,val,posi;
    
    while(true){
        cout<<"\n1.InsertAtBeg\n2.InsertAtEnd\n3.InsertAtPosi\n4.DeleteFirst\n5.DeleteLast\n6.DeleteAtPosi\n7.Print\n8.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"Enter value : ";cin>>val;
                insertAtBeg(head,val);
                break;
            case 2:
                cout<<"Enter value : ";cin>>val;
                insertAtEnd(head,val);
                break;
            case 3:
                cout<<"Enter position and value : ";cin>>posi>>val;
                insertAtPosi(head,posi,val);
                break;
            case 4:
                delFirstNode(head);
                break;
            case 5:
                delLastNode(head);
                break;
            case 6:
                cout<<"Enter position to delete : ";cin>>posi;
                deleteAnyPosi(head,posi);
                break;
            case 7:
                printLL(head);
                break;
            case 8:
                exit(0);
            default:
                cout<<"Invalid Choice!!"<<endl;
        }
    }
    
    return 0;
}
