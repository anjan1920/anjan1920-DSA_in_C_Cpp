//finding specific character in a string
#include<stdio.h>
#include<string.h>
void find_character(char arr[100],char given_ch[100]);
int main(){
    char str[100];
    char ch[100];
    //input
    printf("Enter a string:");
    fgets(str,100,stdin);
    //removing newline from end of the array
    if(str[strlen(str)-1]=='\n'){
        str[strlen(str)-1]='\0';
        
    }
    //input
    printf("Enter a character:");
    fgets(ch,100,stdin);
     //removing newline from end of the array
     if(ch[strlen(ch)-1]=='\n'){
        ch[strlen(ch)-1]='\0';
        
    }
    find_character(str,ch);//fx call
    return 0;
}



//fx definition 
void find_character(char arr[100],char given_ch[100]){
    int i=0,j=0,x=0;
    //search  for character in string
    for(i=0,j=0;arr[i]!='\0' && given_ch[j]!='\0';i++,j++){
        if(arr[i]==given_ch[j]){
            printf("--:%s:character is present on string.");
            x++;
        }
        else{
            continue;
        }

    }
    //if character is not found
    if(x==0){
        printf("--given Character (%s)is not present in (%s) string.",given_ch,arr);
    }
}