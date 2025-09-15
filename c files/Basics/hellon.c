#include<stdio.h>

void printname(char name[]);
void inputfn(char firstname[]);
void inputln(char lastname[]);

int main(){
    char firstname[20];
    char lastname[20];

    inputfn(firstname);
    inputln(lastname);

    
    return 0;
}

void inputfn(char firstname[]){
    int i=0;
    printf("Enter your first name:");
    scanf("%s", firstname);
}

void inputln(char lastname[]){
    int i=0;
    printf("Enter your last name:");
    scanf("%s", lastname);
}

void printname(char name[]){
    int i=0;
    for(i=0;name[i]!='\0';i++){
        printf("%c",name[i]);
    }
    printf(" ");
}
