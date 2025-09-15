
//vowel and consonant counting
#include<stdio.h>
#include<string.h>
int count_vlw_conso(char arr[]);

int  main(){
    char word[100];
    //input from user
    printf("Enter any word:");
    fgets(word,100,stdin);
    count_vlw_conso(word); //fx call
 

    return 0;
}
//fx 
int count_vlw_conso(char arr[]){
    int count=0;
    int conso=strlen(arr)-1;// -1 for eliminate new line character'\n' 
    
   //counting vowel and consonants
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]=='a' ||arr[i]=='e' || arr[i]== 'i' || arr[i]== 'o' || arr[i]=='u'){
            count++;
        }
        if(arr[i]==' '){
            conso--;
        }

    }
    //display output
    printf("Number of vowel in word is %d\n",count);
    printf("Number of consonants is %d",conso-count);
}