#include<stdio.h>

#define n 5


int stack[n];
int top = -1;

// push function
void push(int x) {
    // Check if the stack is full
    if (top == n - 1) {
        printf("Stack Overflow!!\n");
        return;
    } else {
        top++;
        stack[top] = x;
    }
}

// pop function
void pop() {
    // Check if the stack is empty
    if (top == -1) {
        printf("Stack underflow!!\n");
        return;
    } else {
        int temp = stack[top];
        top--;
        printf("%d is popped\n", temp);
    }
}

// peek function
void peek() {
    // Check if the stack is empty
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    } else {
        printf("Peek element of the stack is: %d\n", stack[top]);
    }
}

// display function
void display() {
    // Display the stack elements
    printf("Printing stack (top - bottom):");
    for (int i =n-1; i >= 0; i--) {
        if (i <= top) {
            printf("%d  ", stack[i]);
        } else {
            // Empty spaces
            printf("* ");
        }
    }
    printf("\n");
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
