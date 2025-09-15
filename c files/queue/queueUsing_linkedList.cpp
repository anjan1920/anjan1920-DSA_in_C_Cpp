#include <stdio.h>
#include <stdlib.h>

 struct node {
    int data;
    struct node *link;
};

struct  node *front = 0,*rare = 0,*temp,*newnode;//  front == head , rare == tail

void enqueue(int x) {
    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode ->data = x;
    newnode->link = 0;

    if (front == NULL) {
        front = rare = newnode;
    } else {
        rare->link = newnode;
        rare = newnode;
    }
}

void dequeue() {
    if (front == 0) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }

     temp = front;
    if (front == rare) {
        front = rare = NULL;
    } else {
        front = front->link;
    }

    free(temp);
}

void display() {
     temp = front;
    printf("Printing Queue Front -> Rare: ");
    while (temp != 0) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice,element;

    while (1) {
    	printf("\n----------------------------\n");
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n----------------------------\n");

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
