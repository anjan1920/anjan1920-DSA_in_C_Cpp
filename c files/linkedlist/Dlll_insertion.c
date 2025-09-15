//Doubly linked-list insertion 

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head =0,*tail,*newnode,*temp;

void freeList() {
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL; // Set tail to NULL to indicate an empty list
}


//creation and insertion at end 
void createDll(){
    newnode =(struct node*) malloc(sizeof(struct  node));
    printf("Enter data:");
    scanf("%d", & newnode -> data);
    newnode ->next = 0;
    newnode ->prev = 0;

    if(head == 0){

        head = tail = newnode;
        head ->next = head ->prev = 0;
        
    }else{
        newnode-> prev = tail;
        tail->next = newnode;
        tail = newnode;
        newnode ->next =0;



    }


}

void display(){

    temp = head;
    int count = 0;
    if(head == 0){
        printf("Node is empty .\n");
        return ;
    }printf("\n-----------------------\n");
    printf("printing nodes element :");
    while( temp != 0){
       
        printf("%d ",temp ->data);
        temp = temp ->next;
        count++;
    }
    printf("  Total node :%d",count);
}
//insertion at beginning 
void insert_beginning(){
    if( head == 0){
        printf("No node present .\n");
        return ;
    }else {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d" , & newnode ->data);
        newnode ->prev = 0;
        newnode ->next = head;
        head ->prev = newnode;
        head = newnode;
    }

}


int count_len(){
    temp = head;
    int len =0;
    while( temp != 0){
        temp = temp->next;
        len++;
    }
    return len;
}

////insert at pos
void insert_pos(){
    int len = count_len();
    int pos;
    printf("Enter position :");
    scanf("%d",&pos);
    if( head == 0){
        printf("Node is empty .\n");
        return;
    }else if( pos < 1 || pos > len+1){
        printf("Invalid position !!\n");
        return ;
    }else if(pos == 1){
        insert_beginning();
    }else if( pos == len+1){
        createDll();
        tail =newnode;
    }
    else{
        int i =1;
        temp =head;
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",& newnode -> data);

        while( i<pos-1 ){
            temp = temp->next;
            i++;
        }
        //now temp reach the pos-1 node 
        newnode ->prev = temp;
        newnode ->next = temp->next;
        //new nodes prev and next pointer connected to adjacent nodes
        temp ->next = newnode;
        newnode ->next ->prev = newnode;
        
    }
} 

int main(){

    int choice;
    while(1){
    printf("\n -----------------------------------\n");
    printf("1 .  Insert at end. \n");
    printf("2 . display . \n");
    printf("3 . insert at beginning . \n");
    printf("4 . insert at given pos . \n");
    printf("5 for exit.\n");
    printf("-----------------------------------\n");

    

    printf("Enter choice :");
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
     insert_beginning();
     break;
    case 4:
     insert_pos();
     break;

    case 5:
     freeList();
      return 0;
    
    default:
    printf("Invalid choice!!\n");
        break;
    }
    }
}