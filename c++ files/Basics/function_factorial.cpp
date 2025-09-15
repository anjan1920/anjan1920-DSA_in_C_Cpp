#include<iostream>
using namespace std;

//factorial
void find_fact(){
    int num;
    cout<<"Enter a number to find its factorial:";
    cin>>num;
    int facto=1;
    for(int i=1; i<=num; i++){
        facto=facto*i;

    }
    cout<<"Fcatorial of number("<<num<<") is :"<<facto<<"."<<endl;
}
int main(){
    find_fact();

}