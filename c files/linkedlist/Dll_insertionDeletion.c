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
    printf("printing nodes element -- ");
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
//deletion at beginning 
void del_beginning(){
    if(head == 0){
        printf("Node is empty Deletion can't perform! \n");
        return ;
    }else{
    temp = head;
    temp = head ->next;//temp moves to 2nd node
    temp ->prev = 0;
    free(head);
    head = temp;

    }
}
//deletion at end
void del_end(){
     if(head == 0){
        printf("Node is empty Deletion can't perform! \n");
        return ;
    }else{
        temp = tail;
        temp = tail ->prev ;// temp moves to 2nd last node
        temp ->next = 0;//link braked
        free(tail);
        tail = temp;
    }
}

//deletion at given position
void del_pos(){
    int pos;
    printf("Enter node position to delete:" );
    scanf("%d", & pos);
    int len = count_len();


    if(head == 0){
        printf("Node is empty Deletion can't perform! \n");
        return ;
    }
    else if( pos <1 || pos > len){
        printf("Invalid position !!\n");
        return ;
    }else if(pos == 1){
        del_beginning();

    }else if(pos == len){
        del_end();
    }
    else {
        int i =1;
        struct node *nextNode = head;
        temp = head;
        while( i < pos-1 ){
            temp = temp ->next;

        }
        //temp points on pos-1 node 
        nextNode = temp->next;//newNOde points the pos position node
        temp ->next = nextNode ->next;// link btw pos-1 -> pos+1 node
        nextNode ->next ->prev = temp ;// link btw pos+1 -> pos-1
        //now delete the pos node
        free(nextNode);

    }

    
}
//reverse of dll
void reverseDLL(){
	if( head == 0){
		printf("list is empty.");
		return ;
	}else if( head ->next == 0){
		//single node;
		return ;
	}else {
		
		struct node *currentNode,*nextNode;
		
		currentNode = nextNode = head;
		while(currentNode != 0){
			nextNode = nextNode ->next;
			temp = currentNode->next;
			currentNode ->next = currentNode ->prev;
			currentNode ->prev = temp;
			currentNode = nextNode;
			
		}
	}
	temp = head;
	head = tail;
	tail = temp;
	
}

int main(){

    int choice;
    while(1){
    printf("\n -----------------------------------\n");
    printf("1 . Insert at end. \n");
    printf("2 . Display . \n");
    printf("3 . Insert at beginning . \n");
    printf("4 . Insert at given pos . \n");
    printf("5.  Delete first node .\n");
    printf("6 . last node .\n");
    printf("7 . Delete given position node.\n");
    printf("8.  Reverse the DLL .\n");
    printf("9.  Exit.\n ");
    
    printf("---------------------------------------\n");

    

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
     del_beginning();
     break;

    case 6:
     del_end();
     break;
    case 7:
     del_pos();
     break;

    case 8:
     reverseDLL();
     break;
     
    case 9:
    
     freeList(); 
      
      printf("Exiting program.\n");
      return 0;
    
    default:
    printf("Invalid choice!!\n");
        break;
    }
    }
}
