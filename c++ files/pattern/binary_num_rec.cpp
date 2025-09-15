// 0101
// 1010
// 0101
// 1010
// 0101
#include<iostream>
using namespace std;
int main(){
 
 int r,c;
 cout<< "Enter row and column--"<<endl;
 cin>> r>>c;

for(int i=1;i<=r;i++){

    for(int j=1;j<=c;j++){
        if((i+j)%2==0){
            
            cout <<"0";
        }
        else{

            cout<<"1";
        }
    }
    cout<<endl;
}


 return 0;

}