#include <stdio.h>
#include <string.h>
#include <unistd.h>

void shakerPrint(const char *message) {
    int len = strlen(message);

    while (1) {
        for (int i = 0; i < len; ++i) {
            if (message[i] == ' ') {
                printf(" ");
                usleep(50000); // Sleep for 50 milliseconds for a slight pause between words
                continue;
            }

            for (int j = 0; j <= i; ++j) {
                printf("%c", message[j]);
                fflush(stdout);
                usleep(50000); // Sleep for 50 milliseconds for a slight pause between characters
            }

            printf("\b"); // Move the cursor back to the beginning of the printed characters
            usleep(50000); // Sleep for 50 milliseconds for a slight pause before printing the next character
            printf(" ");   // Print a space to erase the previously printed characters
            printf(" ");   // Print an additional space to maintain spacing between words
            usleep(50000); // Sleep for 50 milliseconds for a slight pause before printing the next word
        }

        printf("\n");
    }
}

int main() {
    const char *message = "fuck you ! fuck you";
    shakerPrint(message);

    return 0;
}

