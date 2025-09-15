#include <stdio.h>
#include <limits.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort jobs by profit in descending order
void sortProfit(int *job, int *profit, int *dLine, int n) {
    // Apply bubble sort
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                swap(&profit[j], &profit[j + 1]);
                // Also swap the job and deadline
                swap(&job[j], &job[j + 1]);
                swap(&dLine[j], &dLine[j + 1]);
            }
        }
    }
    // Sorting done
}

// Job Sequencing function
void jobSequencing(int *job, int *profit, int *dLine, int n) {
    // First apply sorting on decreasing order in profit and also change the job sequence accordingly
    sortProfit(job, profit, dLine, n);

    // Now create a slot array of size = maximum deadline
    int maxDline = INT_MIN;
    int i;
    for (i = 0; i < n; i++) {
        if (dLine[i] > maxDline) {
            maxDline = dLine[i];
        }
    }
    
    int slot[maxDline];
    for (i = 0; i < maxDline; i++) {
        slot[i] = -1; // -1 -> slots as free
    }

    int totalProfit = 0;

    // Now traverse the array of jobs and find the corresponding deadline
    // and place it in the latest possible slot before its deadline.
    for (i = 0; i < n; i++) {
        int dLineValue = dLine[i];

        // Find a free slot for this job (starting from the last possible slot --> from deadline -1  index)
        for (int j = dLineValue - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                //slot is free
                slot[j] = job[i]; // Store job ID in the slot
                totalProfit += profit[i];
                break;
            }
        }
    }

    // Print the result
    printf("Job sequence for maximum profit:\n");
    for (i = 0; i < maxDline; i++) {
        if (slot[i] != -1) {
            printf("Job ID: %d\n", slot[i]);
        }
    }
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter Number of jobs: ");
    scanf("%d", &n);

    int job[n], profit[n], dLine[n];

    // User input
    printf("Enter jobs Profit & Deadline----\n");
    for (int i = 0; i < n; i++) {
        printf("Enter job %d Profit & Deadline: ", i + 1);
        scanf("%d %d", &profit[i], &dLine[i]);
        job[i] = i + 1;
    }

    // Printing the entered values for verification
    printf("Entered values:\n");
    printf("Job\tProfit\tDeadline\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", job[i], profit[i], dLine[i]);
    }


   jobSequencing(job, profit, dLine,  n);
    return 0;
}

//The overall time complexity of the algorithm is O(n^2).
// dominated by the sorting step (Bubble Sort)-O(n^2) 
//with additional O(n * m) time complexity for slot allocation .m size of slot array
// and O(n)for finding the maximum deadline.