#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int rear = -1, front = -1;

void enqueue(int x) {
    // Check if the queue is full
    if (((rear + 1) % MAX_SIZE) == front) {
        printf("Queue is full!\n");
        return;
    } else if (rear == -1 && front == -1) {
        rear = 0, front = 0;
        circularQueue[rear] = x;
    } else {
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = x;
    }
}

void dequeue() {
    // Check if the queue is empty
    if (rear == -1 && front == -1) {
        printf("Queue is empty!\n");
        return;
    } else if (front == rear) {
        rear = -1, front = -1;
    } else {
        int temp = circularQueue[front];
        circularQueue[front] = INT_MIN;
        front = (front + 1) % MAX_SIZE;
        printf("%d item is dequeued.\n", temp);
    }
}

void display() {
    // Display the circular queue, representing empty spaces with "*"
    if (rear == -1 && front == -1) {
        printf("Queue is empty!\n");
        return;
    } else {
    	int i;
        printf("Queue is (Front:%d, Rear:%d): ", front, rear);
        for (i = 0; i < MAX_SIZE; i++) {
            if (circularQueue[i] == INT_MIN) {
                printf("* ");
            } else {
                printf("%d ", circularQueue[i]);
            }
        }
    }

    printf("\n");
}

int main() {
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
                enqueue(num);
                break;
            }
            case 2:
                dequeue();
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
