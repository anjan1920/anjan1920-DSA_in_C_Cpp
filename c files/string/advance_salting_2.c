#include <stdio.h>
#include <string.h>

void salting(char arr[40]);

int main() {
    char password[20];
    printf("Create a password (maximum 16 characters):");
    fgets(password, 20, stdin);
    
    //removing newline character from string
    if (password[strlen(password)-1] == '\n') {
        password[strlen(password)-1] = '\0';
    }
    printf("Given password by user: %s\n", password);
   
   //cheaking if given password>16 or not
    if(strlen(password)<16){
    salting(password);//fx call
      }
      else{
        printf("\n !!! error !please enter maximun 8 character password !!");
      }
    return 0;  
}

//fx defination
void salting(char arr[40]) {
  
    char str1[40];
    char str2[40];
    
    
    // Store the first two characters of the given password in str1
    str1[0] = arr[0];
    str1[1] = arr[1];
    str1[2] = '\0';//termination of str1 on 2 index position

    // Store the rest of the given password in str2
    int i, j;
    for (i = 0, j = 2; arr[j] != '\0'; i++, j++) {
        str2[i] = arr[j];
    }
    str2[i] = '\0';//termination of str2 when rest of characters of arr are moved to str2
    
    // adding salt to str1
    strcat(str1, "@abc2023"); // add salt in str1 salt is ["@abc2023"](@ to 2023) 
    //and str1 lengtg change 2 to 9
   
    strcat(str1, str2);//join str2 on str1 and 
    //str1 length change 9 to rest number of charectar of password 
    
    
    printf("Final salted password: %s\n", str1);
}
