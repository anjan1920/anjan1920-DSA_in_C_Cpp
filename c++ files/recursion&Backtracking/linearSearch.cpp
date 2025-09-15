//Linear search using recursion
#include<iostream>
using namespace std;
bool LS(int arr[],int size,int i,int target){
    if(size == 0) return false;
    if(arr[i]==target) return true;
    LS(arr,size-1,i+1,target);


}
int main(){
    int arr[]={10,20,30,15,45};
    int n = 5;
    int target=-1;
    bool ans = LS(arr,n,0,target);
    cout<<ans<<endl;

return 0;
}
