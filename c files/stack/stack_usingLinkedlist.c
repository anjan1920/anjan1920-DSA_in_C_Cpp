#include<stdio.h>
#include<stdlib.h>
//its same as a single linkedList we just the use head to insertion  and deletion
struct node {
    int data;
    struct node *link;
};

struct node *top =0,*temp,*newNode;
void push(int x){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode ->data = x;
    newNode ->link = top;
    top = newNode;
    
}
//display top - bottom

void display(){
    temp = top;
    printf("printing stack -- ");

    while( temp!= 0){
       
        printf("%d ",temp ->data);
        temp = temp->link;
        
    }
    printf("\n");
}
//peek
void peek(){
    if(top == 0){
        printf("Stack is Empty .\n");
        return;
    }
    printf("Peek element is :%d \n",top->data);
}
//pop
void pop(){
    if( top == 0){
        printf("Stack underflow condition!!\n");

    }else {
        temp = top;
        top = top->link;
        free(temp);
    }
}


int main() {
    int choice;

    while (1) {
        printf("----------------------------------\n");
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for peek\n");
        printf("Enter 4 for display\n");
        printf("Enter 5 for exit\n");
        printf("----------------------------------\n:");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter value to push:");
                scanf("%d", &num);
                push(num);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
            printf("program end.");
                return 0;
            default:
                printf("Invalid input! Please enter a valid option.\n");
        }
    }
}