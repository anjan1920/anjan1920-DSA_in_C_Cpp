#include<stdio.h>
#define n 5
int q[n];
int rear =-1,front =-1;
//Ascending order priority 0>1>2>..
//insertion  operation is sorted manner -> higher priority place such a way so that they dequeue first

void Enqueue(int item){
    int pos;
    //full or not 
    if( rear == n-1){
        printf("Queue is full . \n");
        return ;
    }else{
       // int data = rear;
        pos = rear;
        rear++;

        while(pos >=0 && q[pos] >= item){
            q[pos+1] = q[pos];
            pos = pos-1;
        }
        q[pos +1 ] = item;
        if( front == -1){
            front ++;
         }

    }
}

void Dequeue(){
    if( rear == -1 && front == -1){
        printf("Queue is empty.\n");
    }else{

        int temp = q[front];
        front++;
        printf("%d is dequeued \n.",temp);
    }
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty .\n");
        return ;
    }
    printf("Queue is :");
    for(i =0 ;i< n ;i++){
        if(i>=front && i<=rear ){
            printf("%d ",q[i]);
        }else{
            printf( "* ");
        }
    }
    printf("\n");
}


int main(){
    
     while (1) {
        int choice;
        printf("---------------------------------\n");
        printf("Enter 1 for Enqueue.\n");
        printf("Enter 2 for Dequeue.\n");
        printf("Enter 3 for Display.\n");
        printf("Enter 4 for Exit.\n");
        printf("-------------------------\n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter value to Enqueue: ");
                scanf("%d", &num);
                Enqueue(num);
                break;
            }
            case 2:
                Dequeue();
                break;

            case 3:
                display();
                break;
            case 4:
                printf("Program End.\n");
                return 0;
            default:
                printf("Invalid input! Please enter a valid option.\n");
        }
    }

}