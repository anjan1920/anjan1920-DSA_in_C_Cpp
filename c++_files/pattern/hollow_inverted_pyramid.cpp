// ******
// *   *
// *  *
// * *
// **
// *
#include<iostream>
using namespace std;
int main(){
  int i,j,n;
  cout<<"Enter size:";
  cin>>n;
  for(i=0;i<n;i++){
    for(j=0;j<n-i;j++){
        //print '*' on first and last row and first and last column of pyramid
       if(i==0||i==n-1||j==0||j==(n-i)-1){//n-i-1 hit the last column position of ptramid
        cout<<"*";

       }else{
        cout<<" ";
       }
    }
    cout<<endl;
  }

 return 0;

}