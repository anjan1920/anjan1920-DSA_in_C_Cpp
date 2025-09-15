#include<stdio.h>
int sum(int n);

int main(){
int n,x;
printf("Enter a integer:");
scanf("%d",&x);
printf("%d is sum",sum(x));

return 0;
}

int sum(int n){
if(n==1){
return 1;
}
int sumNm1= sum(n-1);
int sumN=sum(n-1)+n;
}


