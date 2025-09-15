//input output using fx and loop
#include<stdio.h>
void printname(char name[]);
void inputfn(char firstname[]);
void inputln(char lastname[]);

int main(){
    char firstname[20];
    char lastname[20];                                                                  
    inputfn(firstname);//fx call for input
    inputln(lastname);//fx call input

   
    printname(firstname);//fx call
    
    printname(lastname);//fx call
    return 0;
}
//input
void inputfn(char firstname[]){
    printf("Enter your first name: ");
    for(int i = 0; i < 19; i++){
        scanf("%c", &firstname[i]);
        
        if(firstname[i] == '\n'){
            firstname[i] = '\0';
            break;
        }
    }
}
//input
void inputln(char lastname[]){
    printf("Enter your last name: ");
    for(int i = 0; i < 19; i++){
        scanf("%c", &lastname[i]);
        if(lastname[i] == '\n'){
            lastname[i] = '\0';
            break;
        }
    }
}
//output
void printname(char name[]){
    for(int i = 0; name[i] != '\0'; i++){
        printf("%c", name[i]);
    }
    printf(" ");
}
