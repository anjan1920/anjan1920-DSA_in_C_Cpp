//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
// * * * * * 
//  * * * *
//   * * *
//    * *
//     *
//n=5
#include <iostream>
using namespace std;

int main() {
 int n;
 cin>>n;
 //upper portion
 for(int i=0;i<n;i++){
    //space
    for(int j=0;j<n-i-1;j++){
        cout<<" ";
    }
    //star
    for( int j=0;j<i+1;j++){
        cout<<"* ";
    }
    cout<<endl;

 }
 //lower portion
 for(int i=0;i<n;i++){
    //space
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    //star
    for( int j=0;j<n-i;j++){
        cout<<"* ";
    }
    cout<<endl;

 }
 
    return 0;
}