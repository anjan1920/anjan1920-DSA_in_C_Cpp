#include<stdio.h>
int main(){
int n;
printf("Enter a number :");
scanf("%d",& n);
int i=1,sum=0;
do{
sum=sum+i;
i++;
}while(i<=n);
printf("%d is the sum of first :%d natural number",sum,n);

return 0;
}