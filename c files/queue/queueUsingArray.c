#include<stdio.h>
#define n 6
int q[n];
int rear = -1, front = -1;

// Enqueue function
void enqueue(int x) {
    // Check if it is full or not
    if (rear == n - 1) {
        printf("Queue is full.\n");
        return;
    } else if (rear == -1 && front == -1) {
        // Empty case
        rear++;
        front++;
        q[rear] = x;
    } else {
        // Not empty, not full
        rear++;
        q[rear] = x;
    }
}

// Dequeue function
void dequeue() {
    // Check if it is empty or not
    if (rear == -1 && front == -1) {
        printf("Queue is empty.\n");
    } else if (front == rear) {
        // Single element case
        // Reset the queue
        front = -1, rear = -1;
    } else {
        front++;
    }
}

// Display function
void display() {
    int i;

    // Show empty spaces of the queue with -->* and remaining with corresponding values
    if (rear == -1 && front == -1) {
        printf("Queue is empty.\n");
        return;
    } else {
        for (i = n - 1; i >= 0; i--) {
            if (i <= rear && i >= front) {
                printf("%d ", q[i]);
            } else {
                printf("* ");
            }
        }
    }
    printf("\n");
}

// Peek
void peek() {
    if (rear == -1 && front == -1) {
        printf("Queue is empty.\n");
        return;
    } else {
        printf("Peek element is %d\n", q[front]);
    }
}

int main() {

    while (1) {
        int choice;

        printf("----------------------------------\n");
        printf("Enter 1 for Enqueue\n");
        printf("Enter 2 for Dequeue\n");
        printf("Enter 3 for Peek\n");
        printf("Enter 4 for Display\n");
        printf("Enter 5 for Exit\n");
        printf("----------------------------------\n:");

        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int num;
                printf("Enter value to push:");
                scanf("%d", &num);
                enqueue(num);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid input! Please enter a valid option.\n");
        }
    }
}
