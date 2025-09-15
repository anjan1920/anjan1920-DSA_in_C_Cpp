//queue using linkedlist --> FIFO push(),pop() ,T.n-->o(n)
#include<stdio.h>
#include<stdlib.h>

 struct node {
  int data
  struct node *link;
 };
 
 struct node *head=0,*top=0,*temp,*newnode;
 
 void push( int x){
 	
 	newNode = (struct node*)malloc(sizeof(struct node));
 	printf("Enter data:");
 	scanf("%d", newNode ->data );
 	if( head == 0){
 		head = top = newNode ;
 		newNode ->link = 0;
	 }else {
	 	top->link = newNode ;
	 	top = newNode ;
	 	newNode ->link = 0;
	 }
 	
 	
 	
 }
 
 voi pop(){
 	if(head == 0){
 		printf("Queue is empty.\n");
 		return;
	 }else if( head == top){
	 	//only single node present 
	 	free(head);
	 	head = top =0;
	 }else{
	 	//more than one delete from head
	 	temp = head;
	 	temp = temp->link;
	 	free(head);
	 	head = temp;
	 	
	 }
 }
 
 void display(){
 	//print from bottom to top
 	temp=head;
 	printf("printing Queue Front -> Rare :");
 	while(temp != 0){
 		printf("%d ", temp->data);
 		temp = temp->link;
	 }
	 printf("\n");
 	
 }
 
 

int main(){
	push(1);
	push(2);
	push(3);
	display();
	pop();
	display();
	
	
}
