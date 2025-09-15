//String leangth  

#include<stdio.h>
int strleangth(char arr[]);
int strleangth1(char arr[]);


int main(){
    
    printf("Enter you name without space:");
    char name[100];
    char name1[100];
    //input from user 
    for(int j=0;j<99;j++){
        
        scanf("%c",& name[j]);
        if(name[j]=='\n'){
            name[j]='\0';
            break;
        }
    }
    
    printf("string leangth =%d\n",strleangth(name));//fx call 
    //input from user 
    printf("Enter you name  full name:");
    for(int j=0;j<99;j++){
        
        scanf("%c",& name1[j]);
        if(name1[j]=='\n'){
            name[j]='\0';
            break;
        }
    }
    printf("string leangth =%d\n",strleangth1(name));//fx call


return 0;

}
//output including space
int strleangth(char arr[]){
    int count=0, i=0;
    for(i=0;arr[i]!='\0';i++){
        count ++;
    }
    return count;
}
//output excluding space
int strleangth1(char arr[]){
    int count=0, i=0;
    //removing space
    for(i=0;arr[i]!='\0';i++){
        count ++;
        if(arr[i]==' '){
            count--;
        }
    }
    return count;
}


