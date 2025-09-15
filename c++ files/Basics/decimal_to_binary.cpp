#include<iostream>
using namespace std;
void dec_binary(){
int dec;
int binary =0;
int base=1;
cout << "Enter decimal number:" ;
cin >> dec;

int temp=dec;
if(temp==0){
cout<<binary<<endl;
} else{
//
while(temp>0){
int lastdigit=temp%2;
binary=binary+ lastdigit*base;
temp=temp/2;
base=base*10;


}
}
cout << "Binary is=" <<binary<<endl;
}
int main(){

dec_binary();
return 0;


}



