//rotation using  %
#include<iostream>
using namespace std;

void print(int arr[],int n){
    int i=0;
    for(int i=0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}
//rotation
void rotation_arr(int arr[],int n){
    int k;
    int i=0;
    cout<<"Enter number of rotation:";
    cin>>k;
    k=k%n;//for making k<=n

    int temp[n];

    while( i<n ){
        int next= (i + k) % n;//find the next index
        temp[next]=arr[i];//store main array index element to next(rotation position) index of temp array
        i++;

    }
   // print(temp,n);

    //the main array i/s clear and we store the temp array element to main array;
    for(int j=0 ;j< n ;j++){
        arr[j]=temp[j];//

    }

    print(arr,n);

}

int main(){
    int arr[]={1,2,3,4,5,6,0};
    int  n=7;
print(arr,n);
rotation_arr(arr,n);

}