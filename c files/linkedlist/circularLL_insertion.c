#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//global
struct node *head=0,*tail=0,*newNode,*temp;

//****count length of linked list****
int countLen(){
     int count =1;
    if( head == 0){
        return 0;
    }else if(head == tail ){
        //single node 
        return 1;
    }else{
       
        temp = head;
        temp = head ->next;//move temp to next node 
        while(temp != tail){
            count++;
            temp = temp->next;
        }
        count++;
    }
    return count;

}
//**display  ***
void display() {
    int count =0;
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
    } else if(tail == head){
        printf("printing Nodes element --");
        count =1;
        printf("%d ",head ->data);
    }else{
        printf("printing Nodes Element :");
            temp = head;
          //first we print head node then move the temp
            printf("%d ", temp->data);
            temp = temp->next;
            count++;
        //the loop print 2nd node to 2nd last node
         while (temp != tail){
            printf("%d ",temp->data);
            temp = temp->next;
            count++;
        }
        //now loop fail to print last node data
        printf("%d ", temp->data);
        count++;
        
    }
    printf(" . Total number of Nodes : %d\n",count);
}
//creation of dll and insertion  at end
void createDll(){
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",& newNode ->data);
    //if already no node present
    if( head == 0){
        head = newNode;
        tail = head;
        //single node CLl created
    }else{
        //one or more than one node already present 
        //tail should points current last node
        tail->next = newNode;
        newNode ->next = head;
        tail = newNode;

    }
}

//insertion at beginning 
void insertBeginning(){
    //empty or not
    if( head == 0){
        //empty
        printf("Node is empty insertion at beginning is not possible.\n");
        return ;
    }else{
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", & newNode ->data);

        newNode ->next = head;
        head = newNode;
    }

}

//insertion at given position

void insertPos(){
    int len =countLen();

    if( head == 0){
        //empty
        printf("Node is empty insertion not possible.\n");
        return ;
    }else {
        int pos ;
        printf("Enter position to insert new Node:");
        scanf("%d",& pos);

        if( pos <1 || pos >len+1 ){
            printf("Invalid position !!\n");
            return ;
        }else if( pos == 1){
            insertBeginning();
        }else if( pos ==  len+1 ){
            createDll();
        }else {
            newNode = (struct node *)malloc(sizeof(struct node));
            struct node *nextNode;
            printf("Enter Data:");
            scanf("%d", & newNode -> data);
            temp = head;
            int i =1;

            while( i< pos-1 ){
                temp = temp->next;
                i++;
            }
            //now the temp points the pos-1 number node
            nextNode = temp -> next;//this pointer points pos number node;
            temp ->next = newNode;
            newNode ->next = nextNode ;


        }
    }
}

int main(){

    while(1){

    int choice;
    printf("--------------------------------------------\n");
    printf("Enter 1 for create node\n");
    printf("Enter 2 for display node\n");
    printf("Enter 3 for Insert node at beginning.\n");
    printf("Enter 4 for Insert node at random position.\n");
    printf("Enter 5 for exit \n");
    printf("--------------------------------------------\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        createDll();
        break;
    case 2:
        display();
        break;
    case 3:
        insertBeginning();
    
        break;
    case 4:
        insertPos();
        break;
    case 5:
        return 0;
   
    default:
     printf("Invalid Input !! Try again.\n");
        break;
    }
    }

    

}