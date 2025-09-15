#include <stdio.h>

int main() {

  int n, rev = 0, rem,temp;


  printf("Enter an integer: ");
  scanf("%d", &n);
  temp = n;
  while (n != 0) {
    rem = n % 10;
    rev = rev* 10 + rem;
    n /= 10;
  }

  printf("Reversed number = %d\n", rev);
  
  if(temp == rev){
    printf("%d is palindrome:",temp);

  }
  else{
    printf("%d is not palindrome",temp);
  }

  return 0;
}