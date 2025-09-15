//Basic calculator using switch case:
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float x,y;
    char choise;
//input
    cout << "Enter first number:";
    cin>> x;
    cout << "Enter opetaion:(+,*,/,^):";
    cin >>choise;
    cout << "Enter second number:";
    cin >> y;

 //checking user input 
    if(choise=='+'||choise=='*'||choise=='/'||choise=='!'||choise=='^'){
        //switch case
        switch(choise){
            case '+':
            cout << "sum value is "<<x+y <<endl;
            break;

         case '*':
            cout << "Product is "<<x*y <<endl;
            break;
         case '/':
            cout << "Division is "<<x/y <<endl;
            break;
         case '^':
          cout << "power is "<<pow(x,y) <<endl;
          
            break;
        defult :
        cout << "Invalid input!";





        }

    }else{
        cout << "Invalid input!!"<< endl;

    }


return 0;
}