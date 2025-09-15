//str leangth using str library 
#include<stdio.h>
#include<string.h>

int strleangth(char arr[]);
int main(){
    char name[100];
   
    printf("Enter your name with out space:");
    fgets(name,100,stdin);//user by input
    printf("%d -- is leangth \n",strleangth(name));//fx call
    

    return 0;

}

//output including space
int strleangth(char arr[]){
   int lnth= strlen(arr);
   if(arr[lnth-1]=='\n'){
   
    lnth--;
     }
     return lnth;
}
