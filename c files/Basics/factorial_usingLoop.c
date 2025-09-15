#include<stdio.h>
int main(){
int n;
printf("Enter a number:");
scanf("%d",&n);
int fact=1;
for(int i=1;i<=n;i++){
fact=fact*i;
}

printf("%d is factorial valule of %d",fact,n);

return 0;
}