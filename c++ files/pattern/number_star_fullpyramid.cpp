// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 5*5*5*5*5
// 4*4*4
// 3*3
// 2
//n=5
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i,j;
    //uper part
    for( i=0;i<n;i++){
        //
        for( j=0;j<2*i+1;j++){
            if(j%2==0){
                cout<<i+1;
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
//lower part
for(i=0;i<n-1;i++){//we set o ined on lower part and extend it< n-1=(4-1)=4,run 0,1,2 
    for(j=0;j<(n)-2*i;j++){//iner loop run <n-2i=(when i=0) run<5-(2*0)=5,-0,1,2,3,4
         if(j%2==0){
                cout<<(n-1-i);//
            }else{
                cout<<"*";
            }
    }
    cout<<endl;

}

    return 0;
}