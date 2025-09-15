#include <stdio.h>

// Function to swap two floats
void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on profit-to-weight ratio in descending order
void sortByRatio(int num, float ratio[], float weight[], float profit[], int originalIndices[]) {
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios, weights, profits, and original indices
                swapFloat(&ratio[j], &ratio[i]);
                swapFloat(&weight[j], &weight[i]);
                swapFloat(&profit[j], &profit[i]);
                swapFloat(&originalIndices[j], &originalIndices[i]); //also change the original index as the obj get change its place
            }
        }
    }
}

// Function to solve the fractional knapsack problem
void knapsack(int num, float weight[], float profit[], float capacity, int originalIndices[]) {
    float x[num], totalProfit = 0;
    float remainingCapacity = capacity;

    // Initialize result vector
    for (int i = 0; i < num; i++) {
        x[i] = 0.0;
    }

    // Calculate profit-to-weight ratios
    float ratio[num];
    for (int i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items by profit-to-weight ratio
    sortByRatio(num, ratio, weight, profit, originalIndices);

    // Use the original index to fill the knapsack 
   // we fill the knapsack in the order that the original object was given --> 
   //The ration is selected based on the p/w ratio, 
   //and it is then inserted into the index of x  where the object was initially placed in the array. 
    for (int i = 0; i < num; i++) {
        int originalIndex = originalIndices[i];
        if (weight[i] <= remainingCapacity) {
            x[originalIndex] = 1.0; // Take the whole item
            totalProfit += profit[i];
            remainingCapacity -= weight[i];
        } else {
            x[originalIndex] = remainingCapacity / weight[i]; // Take a fraction of the item
            totalProfit += x[originalIndex] * profit[i];
            break; // Knapsack full
        }
    }

    // Print result 
    printf("\nThe result vector is:- ");
    for (int i = 0; i < num; i++) {
        printf("%f\t", x[i]);
    }

    // Print maximum profit
    printf("\nMaximum profit is:- %f", totalProfit);
}


int main() {
    int num;
    printf("\nEnter the number of objects: ");
    scanf("%d", &num);

    float weight[num], profit[num];
    int originalIndices[num]; // Array to store original indices of objects

    printf("\nEnter the weights and profits of each object:\n");
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        originalIndices[i] = i; // Store original index
    }

    float capacity;
    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Solve knapsack problem
    knapsack(num, weight, profit, capacity, originalIndices);

    return 0;
}
