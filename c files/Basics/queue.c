#include <stdio.h>

// Function prototypes
int enq(int q[], int n, int *r, int *f);
int dq(int q[], int n, int *r, int *f);

int main() {
    int n = 4 ;
    int q[n];
    int r = -1, f = -1;

    while (1) { // Infinite loop to display the menu until user chooses to exit
        // Choice
        int ch;

        printf("\nEnter your choice.\n---Menu--\n");
        printf("1.Enqueue.\n");
        printf("2.Dequeue.\n");
        printf("3.Exit.\n:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enq(q, n, &r, &f);
                break;
            case 2:
                dq(q, n, &r, &f);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

int enq(int q[], int n, int *r, int *f) {
    if (*r== n-1) {
        printf("Queue is full. Cannot enqueue.\n");
        return -1; // Return an error code
    } else {
         if (*f == -1 && *r==-1) {
            *f = 0; // Update the front pointer if it was -1 (empty queue)
            *r=0;
        }

        int data;
        printf("Enter data: ");
        scanf("%d", &data);

        
        q[*r] = data;
        (*r)++;
        

       

        return 0; // Return success code
    }
}
int dq(int q[], int n, int *r, int *f) {
    if (*r==-1 && *f==-1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error code
    } else {
        int removed = q[*f];
        (*f)++;

        // Check if the queue is now empty
        if (*f > *r) {
            *f = -1;
            *r = -1;
        }

        printf("Dequeued: %d\n", removed);
        return 0; // Return success code
    }
}
