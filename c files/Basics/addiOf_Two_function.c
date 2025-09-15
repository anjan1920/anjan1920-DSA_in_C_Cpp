#include<stdio.h>
int addi(int n,int m);

int main(){
int x,y;
printf("Enter two nuber \n :x=");
scanf("%d", & x);
printf(":y=");
scanf("%d", & y);
printf("%d id summation of %d + %d",addi(x,y),x,y);
return 0;
}
//fx defination
int addi(int n, int m){
int addfinal=n+m ;
return addfinal;


}


