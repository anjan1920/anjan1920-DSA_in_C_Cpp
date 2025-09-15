#include <stdio.h>

int main() {
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int temp=1;
    if(n==0 || n==1){
        temp=0;
    }
    for(int i=2;i<n/2;++i){
        if(n%i==0){
            temp=0;
            break;
        }
    }
    if(temp==1){
        printf("%d is prime.",n);
    }
    else {
        printf("%d is not prime.",n);
    }
    return 0;
}
