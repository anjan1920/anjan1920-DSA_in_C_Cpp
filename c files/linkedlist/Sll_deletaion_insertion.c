//creation of SLL and insertion and deletion
#include<stdio.h>
#include<stdlib.h>

//user define data structure
struct node{
    int data;
    struct node *next;
};

struct node  *head=0 ,*new_node , *temp;



//creation of node
int count_node(){
    temp = head;
    int count =0;
      while( temp!= 0){
       // printf(" %d |",  temp ->data);
        temp = temp  ->next;
        count++;

    }
    return count;
}
//

void create_node() {
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;  // The new node will be the last node, so its next should be NULL

    if (head == NULL) {
        // no node present
        head = new_node;
        temp = new_node;
    } else {
        // more than one node --> head already connected, find the last node
        temp= head;
        while (temp->next != 0) {
            temp = temp->next;
        }

        // Connect the new node to the last node
        temp->next = new_node;
        temp = new_node;  // Update temp to point to the new last node
    }
}


    
   


//insert node at beginning  
void insert_beginning(){
    if(head == 0){
      //  means no node present
      printf("No node present !.\n");
      return ;
    }

    new_node =(struct node*) malloc(sizeof(struct  node));
    printf("Enter data:");
    scanf("%d", & new_node -> data);
    new_node ->next = 0;
    //now we have to connect it to the first node

    
    new_node ->next = head;
    head = new_node;

  
}

void insert_givenpos() {
    int pos;
    printf("Enter position where you want to insert new node:");
    scanf("%d", &pos);

    int count = count_node();
    if (pos > count + 1 || pos < 1) {
        printf("Invalid position!!\n");
    } else {

        // If inserting at the beginning
        if (pos == 1) {
            insert_beginning();
        } else {
            
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
       
        printf("Enter data:");
        scanf("%d", &new_node->data);

            int i = 1;
            temp = head;
            while (i < pos - 1) {
                temp = temp->next;
                i++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

//deletion at beginning 

void del_beginning(){

    //first check if the list is empty or not
    if(head ==0 ){
        printf("LinkedList is empty  deletion not possible .!\n ");
        return ;
    }else{
        temp = head ;
        head = temp->next;//head now move to next node
        free(temp);//its free the memory allocation of the first node
        temp = head;//not necessary
    }
}

//deletion at end
void del_end(){
    if(head == 0 ){
        printf("LinkedList is empty  deletion not possible .!\n ");
        return ;
    }else if( head ->next == 0){
        //only one node present 
        free(head);
        head =0;
    }else{
    temp = head;
    struct node *prevnode;

    while( temp ->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    //now temp points at the last node and prevnode points at it's previous node
    prevnode ->next = 0;
    free(temp);
    temp  = head;
    
    }

}
//deletion at any given position 

void del_pos(){
    int pos;
    printf("Enter Position :");
    scanf("%d",& pos);
    if( pos > count_node()  || pos <1){
        printf("Invalid position !!\n");
        return ;
    }else if(pos == 1){
        del_beginning();
        
    }else {
        struct node *nextnode ;
        temp = head;
        int i=1;

        while( i < pos-1){
            temp = temp->next;
            i++;
        }
        //now temp reach the pos -1 position node
        nextnode = temp ->next;//points the next node of temp --> pos node
        temp ->next = nextnode->next;// connection stablish  btw node(pos-1) to node(pos+1);
        //now just delete the pos node
        free(nextnode);
        temp = head;

    }
}

void reverseSLL(){

    if(head == 0){
        printf("list is empty.\n");
        return ;
    }else if( head ->next == 0){
        //single node 
        return;
    }else{
        struct node *currentNode,*prevNode=0,*nextNode;
        nextNode = currentNode = head;

        while(nextNode != 0){

            nextNode = nextNode ->next;
            currentNode ->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;

        }
        //at the end current and next node points to 0, and prev points to last node

        head = prevNode;
        
    }
}

//display function 

void display(){
    temp = head;
    int count =0;
    if(head == 0){
        printf("No node available.\n");
    }else
    {   
         printf("Printing nodes element --\n");
        while( temp!= 0){
        printf(" %d |",  temp ->data);
        temp = temp  ->next;
        count++;

    }
    printf("\ntotal number of node is :%d \n",count);
    }
}

int main(){
    while(1){

    int choice;
    printf("--------------------------------------------\n");
    printf("Enter 1 for create node.\n");
    printf("Enter 2 for display node.\n");
    printf("Enter 3 for Insert node at beginning.\n");
    printf("Enter 4 for Insert node at random position.\n");
    printf("Enter 5 deletion at beginning \n");
    printf("Enter 6 deletion at end. \n");
    printf("Enter 7 deletion at random position. \n");
    printf("Enter 8 reverse the linkedlist. \n");
    printf("Enter 9 Exit \n");
    printf("--------------------------------------------\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        create_node();
        break;
    case 2:
        display();
        break;
    case 3:
        insert_beginning();
    
        break;
    case 4:
        insert_givenpos();
        break;
    case 5:
        del_beginning();
        break;
    case 6:
      del_end();
      break;
    case 7:
      del_pos();
      break;
    case 8:
     reverseSLL();
     break;
    case 9:
    printf("program End.");
     return 0;

   
    default:
     printf("Invalid Input !! Try again.\n");
        break;
    }
    }

}
