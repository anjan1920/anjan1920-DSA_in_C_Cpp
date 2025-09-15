#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime or not
bool is_prime(int num) {
    if (num < 2) {
        // A number less than 2 cannot be prime
        return false;
    }
    
    // Check if the number is divisible by any number from 2 to num-1
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            // If the number is divisible by any of these numbers, it's not prime
            return false;
        }
    }
    
    // If the number is not divisible by any number from 2 to num-1, it's prime
    return true;
}

int main() {
    int start, end;

    // Prompt the user to enter the range of numbers
    printf("Enter the range of numbers: ");
    scanf("%d %d", &start, &end);

    // Print the list of prime numbers between the given range
    printf("List of prime numbers between %d and %d:\n", start, end);

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            // If the number is prime, print it
            printf("%d ", i);
        }
    }

    // Add a newline after the list of prime numbers for better formatting
    printf("\n");

    return 0;
}
