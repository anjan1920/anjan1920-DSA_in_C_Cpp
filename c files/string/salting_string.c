
//salting basic
#include<stdio.h>
#include<string.h>
void salting(char arr[40]);
int main(){
 char name[20];
 printf("Create a pasasword max 8 charectar:");
 //eliminate space from string
 fgets(name,20,stdin);
  if (name[strlen(name)-1] == '\n') {
        name[strlen(name)-1] = '\0';
    }
 printf(" Given pass. by user--%s\n",name);
 salting(name);  //fx call
 return 0;  
}

//fx defination
void salting(char arr[40]){
    char saltedpass[strlen(arr)+3];//+3 for soring salt
    strcpy(saltedpass,arr);//make a copy of :arr: string and store on : saltedpas: string 
    strcat(saltedpass,"123");//store 123 salt on :saltedpass : string
    printf("Salted password is %s",saltedpass);
}
