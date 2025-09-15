//creation of SLL and traversing 
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

void create_node(){

    
    new_node = (struct node *)malloc(sizeof(struct node)); //malloc return a void pointer of 8(32bit) byte memory 
    //then we convert its pointer to "struct node" data type
    printf("Enter data :");
    scanf( "%d" , & new_node ->data);
    new_node ->next = 0;
    //till now we create a node then its next store the "null" . 
    //now we have to connect it to previous node if present

    if( head == 0){
        // just only one node 
        head = new_node;
        temp = new_node;
    }else{
        //more than one node
        temp ->next = new_node;
        temp = new_node;// temp move to next node
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
    printf("\n total number of node is :%d \n",count);
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
        return 0;
   
    default:
     printf("Invalid Input !! Try again.\n");
        break;
    }
    }

}
