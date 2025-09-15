#include<stdio.h>
int main(){
int n,prime=1;

printf("Enter a number:");
scanf("%d",& n);

for(int i=2;i<n;i++){
if((n%i)== 0){
prime = 0;
}

}
if(prime==0){
printf("%d is not a prime \n",n);
}
else{
printf("%d is a prime number \n",n);
}
return 0;
}



