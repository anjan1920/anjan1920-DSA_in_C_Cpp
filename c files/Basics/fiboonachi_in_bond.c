#include<stdio.h>
int fib_bond(int start ,int end){
    int nm1=0;
    int nm2=1;
    int next=0;
    while(nm1<=end){
        if(nm1>=start){
            printf("%d\t",nm1);
        }
        next=nm1+nm2;
        nm1=nm2;
        nm2=next;
    }
}
int main(){
    int start,end;
    printf("Enter lower bond:");
    scanf("%d",&start);
    printf("\nEnter upper bond:");
    scanf("%d",&end);
    fib_bond(start,end);
  
return 0;
}