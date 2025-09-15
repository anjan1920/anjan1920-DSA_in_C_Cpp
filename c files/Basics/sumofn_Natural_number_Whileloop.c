#include<stdio.h>
int main(){

int n;
printf(":Enter a number:");
scanf("%d",&n);

int i=1,sum=0;
while(i<=n){
sum=sum+i;
i++;
}
printf("%d is sum of first %d natural number",sum,n);

return 0;

}