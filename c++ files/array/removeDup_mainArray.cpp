//this program remove duplicate by modify the main array and give ouput  of array unique element 
//and rest of the array is not impotent  and number of unique element
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&v){
for( int i=0 ;i< v.size() ;i++){
	cout<<v[i]<<" ";
	
}
cout<<endl<<"printing done--- "<<endl;

}
int main(){
    vector<int> arr={ 1,1,2,2,3,4,5,5,6,7};
    int i=1,j=0;
    print(arr);

    while( i< arr.size()){
        if(arr [ i ] == arr[j]){
            //move j
         i++;
    }else{
        //move i to one place then store the arr[j] to i position
        j++;
        arr[j] = arr[i];
        i++;
    }

    }
    print(arr);
    
    cout<<j+1<<endl;
    

}