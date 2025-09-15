#include <stdio.h>
#include <string.h>

void joint_word(char word[100]);

int main() {
    char string[100];
    printf("Enter word line:");
    fgets(string, 100, stdin);//user from input
    //removing new line character from end
    if (string[strlen(string)-1] == '\n') {
        string[strlen(string)-1] = '\0';
    }
    printf("--%s :is given word line\n", string);
    joint_word(string);//fx call
    return 0;
}

//fx defination
void joint_word(char word[100]) {
    int i, j;
    char joint[100];
    //copying word string on joint excluding space
    for (i = 0, j = 0; word[i] != '\0' && j < 100; i++) {
        if (word[i] != ' ') {
            joint[j] = word[i];
            j++;
        }
    }
    joint[j] = '\0';
    printf("%s\n", joint);
}
