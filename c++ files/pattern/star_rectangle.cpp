//retangular pattern print
// ****
// ****
// ****
#include<iostream>
using namespace std;
int main(){
    int row,colm;
    cout<<"Enter row and colm:";
    cin>>row;
    cin>>colm;

    int i,j;
//nested loop
for(i=1;i<=row;i++){
    
    for(j=1;j<=colm;j++){
        cout << "*";
    }
    cout<<endl;
}


return 0;
}