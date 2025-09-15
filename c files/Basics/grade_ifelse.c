#include <stdio.h>
int main() {
int mark;
printf("What is your total percentage  ?\n");
scanf("%d", & mark);
if(mark >= 95){
printf("  you grade is AA\n");
}
else if(mark <95 && mark >=90){
printf("your grade is A+\n");
}
else if(mark <= 89 && mark >= 80){
printf("your grade is A\n");

}
else if(mark<=79 && mark>=70){
printf("Your grade is B+\n");
}
else if(mark <= 69 && mark >= 60){
printf("your garde is B\n");
}
else if (mark <= 59 && mark >=50){
printf("your garde is C+\n");
}
else if(mark <= 49 && mark >= 30){
printf ("your  gade is C\n");
}
else if ( mark<= 30 && mark >=0){
    
printf("you failed!!");

}
 return 0;

}
