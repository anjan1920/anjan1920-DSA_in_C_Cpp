//string swap 
#include<stdio.h>
#include<string.h>
void reverse(char arr[100]);
int main(){
    char arr[100];
    printf("Enter charectar:");
    fgets(arr,100,stdin);//input
    reverse(arr);//fx cxall
    return 0;
}
void reverse(char arr[100]){
    int i=0;
    
    for(i=strlen(arr)-1;i>=0;i--){
        printf("%c",arr[i]);
    }
}