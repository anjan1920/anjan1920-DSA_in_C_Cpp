//creation of SLL and traversing 
#include<stdio.h>
#include<stdlib.h>

//user define data type 


struct node{
    int data;
    struct node *next;
};

struct node  *head=0 ,*new_node , *temp;



//creation of node

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
    printf("Enter 1. for create node\n");
    printf("Enter 2 for display node\n");
    printf("Enter 3 for exit \n");
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
        return 0;
    
    
    default:
     printf("Invalid Input !! Try again.\n");
        break;
    }
    }

}
