#include <stdio.h>
int linear_serach(int arr[],int n,int x){
  int i=0;
  for(i=0;i<n ;i++){
    if(arr[i]==x){
      return i;
    }
    else{
      continue;
    }

  }
  return -1;
}

int binary_search(int arr[], int n, int x) {
  int left = 0;
  int right = n - 1;

  // Searching
  while (left <= right) {
    int mid = (right + left) / 2;

    if (arr[mid] == x) {
      return mid;
    }

    if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int x;
 
  int arr[] = {1, 5, 6, 8, 9, 15};
  int size = sizeof(arr) / sizeof(arr[0]);
  int sw;
printf("Enter 1 for linear short:");
printf("\nEnter 2 for binary short:");
scanf("%d",&sw);
switch(sw){
case 1:
  printf("Enter the number you want to search: ");
  scanf("%d", &x);

  int result = binary_search(arr, size, x);

  if (result == -1) {
    printf("%d is not present in the array.\n", x);
  } 
  else {
    printf("%d is present at index %d.\n", x, result);
  }
  break;
  case 2: 
   printf("Enter the number you want to search: ");
  scanf("%d", &x);

  int result1=linear_serach(arr,size,x);
  if(result1==-1){
    printf("\n not present");
  }
  else{
    printf("%d is present on %dindex",x,result1);
  }

 break; 
 default:
 printf("Wrong enter:");


}
  
  return 0;
}
