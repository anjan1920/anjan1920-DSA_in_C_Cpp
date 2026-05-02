//diamond alphabet pattern
//     A
//    ABC
//   ABCDE
//  ABCDEFG
// ABCDEFGHI
// ABCDEFGHI
//  ABCDEFG
//   ABCDE
//    ABC
//     A
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
 // alphabet
 for(int k=1 ;k<=(2*i-1); k++){
   //for alphabet conversion 
  int temp=64+k ;//A(65)-1=64+k(1,2,3,4)

  cout<<(char)temp;
  

 }

 cout<<endl;

 }

//lower portion of pattern
for(i=n ; i>=1 ; i--){
   //for space
    for(int k=1 ;k<=(n-i);k++){
        cout <<" ";
    }
 //for alphabet
 for(int k=1 ;k<=(2*i-1); k++){
   //for alphabet conversion 
  int temp=64+k ;//A(65)-1=64+k(1,2,3,4)

  cout<<(char)temp;
  


 }

 cout<<endl;

 }




return 0;
}

