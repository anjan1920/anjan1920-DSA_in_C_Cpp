#include <stdio.h>
#include <string.h>

const char *identify_salt(const char *salted_password) {
    if (strstr(salted_password, "na2023@") == salted_password + 2) {
        return "na2023@";
    } else if (strstr(salted_password, "@abc2023") == salted_password + 2) {
        return "@abc2023";
    } else if (strstr(salted_password, "adas#2023") == salted_password + 2) {
        return "adas#2023";
    } else {
        return "Unknown salt";
    }
}

int main() {
    char salted_password[60]; // Adjust size as needed
    printf("Enter the salted password: ");
    fgets(salted_password, sizeof(salted_password), stdin);

    // Removing newline character from string
    if (salted_password[strlen(salted_password) - 1] == '\n') {
        salted_password[strlen(salted_password) - 1] = '\0';
    }

    const char *salt = identify_salt(salted_password);

    if (strcmp(salt, "Unknown salt") == 0) {
        printf("Unrecognized salt\n");
    } else {
        printf("Identified salt: %s\n", salt);
    }

    return 0;
}
