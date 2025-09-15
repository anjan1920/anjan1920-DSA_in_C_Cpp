#include<stdio.h>
int main(){
int x,y,z;
printf("Enter numbers :\n x= ");
scanf("%d",&x);
printf(" y=");
scanf("%d",&y);
printf(" z=");
scanf("%d", & z);
if(x>=y && x>=z){
 printf("%d is largest\n",x);
 
}
if(y>=z && y>=x){
printf("%d is largest",y);
 }
if(z>=x && z>=x){
printf("%d is largest\n",z);
}
return 0;

}