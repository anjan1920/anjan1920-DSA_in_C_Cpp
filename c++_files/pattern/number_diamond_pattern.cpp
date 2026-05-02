
//number diamond pettern
//    1
//   123
//  12345
// 1234567
// 1234567
//  12345
//   123
//    1
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i,j;
//upper portion of pattern
 for(i=1 ; i<=n ; i++){
   //for space
    for(int k=1 ;k<=(n-i);k++){
        cout <<" ";
    }
 //number print
 for(int k=1 ;k<=(2*i-1); k++){

 cout<<k;

 }

 cout<<endl;

 }

//lower portion of pattern
for(i=n ; i>=1 ; i--){
   //for space
    for(int k=1 ;k<=(n-i);k++){
        cout <<" ";
    }
 //number print
 for(int k=1 ;k<=(2*i-1); k++){
   cout<<k;


 }

 cout<<endl;

 }




return 0;
}

