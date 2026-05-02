#include<iostream>
#include<vector>
using namespace std;
//n=row*column
//Total T.n= O(n^2){for copy function} +O(n^2){for print function} +O(long n){for binary search} =O(n^2)
void print (vector<vector<int>>&nums){

    for( int i=0 ;i<nums.size();i++){
        for( int j=0 ;j<nums[i].size();j++){
            
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}

//2d to 1d conversion
vector<int> twoDto1D( vector<vector<int>>&nums ){

    //copy all element of the 2d array in a 1d array
    vector<int>temp;
    int el=0;
    for(int i=0 ;i<nums.size();i++){
        for( int j=0 ;j<nums[i].size();j++){
            temp.push_back( nums[i][j]);
        }
    }
    cout<<"Copy operation done"<<endl;

    return temp;

}
//binary search in 1d mmatrix

int binary2d(vector<int>&nums,int target){
    int n= nums.size();
    int s=0 ,e=n-1,mid;
    int ans=-1;

    while( s<=e ){

        mid = s+ (e-s) /2;//its also work ( s+e )/2 but its over flow when s and e are close to INT_MIN value

        //found case
        if( nums[mid] == target){
            ans = mid;

            return ans;
        }else if( target > nums[mid] ){

            //go towards  right
            s= mid +1;

        }else if( target< nums[mid] ){
            //go towards left
            e = mid-1;
        }

        


    }
    return ans;
    
}
int main(){
  
    vector <vector<int>>nums= {{ 1,2,3},{5,6,7},{8,9,10}};
    print(nums);
    int target;
    cout<<"Enter target:";
    cin>>target;
    //convert 2d matrix to 1d matrix
    vector<int>temp =twoDto1D(nums);
    //perform the binary serach in the Temp 1d array
    int ans = binary2d(temp,target);

    if( ans !=-1){
        cout<<"true";
    }else{
        cout<<"False";
    }

    return 0;
   

}