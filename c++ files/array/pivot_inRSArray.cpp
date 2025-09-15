#include<iostream>
#include<vector>


using namespace std;
//find pivot in rotated and  sorted array
    
int  findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <=e ) {
            //corner case
            if(s == e) {
                //single element
                return s;
            }

            if(mid+1 < n && arr[mid] > arr[mid+1]){
                //when mid is ans
            //mid +1 < n condition overcome the case 
             //mid = n-1 then mid+1 out of range
                return mid;
            }
            else if(mid-1 >=0 && arr[mid] < arr[mid-1]){
                //when mid-1 is ans
                return mid-1;
            }
            else if(arr[s] > arr[mid] ) {
                //in B range go left
                e = mid - 1;
            }
            else 
            //go right
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
    return -1;
   
}

    

int main(){
    vector<int>nums ={ 10,11,12,13,14,9,10,11,12}; // 14 is pivot index 
    int ans = findPivotIndex( nums);
    cout<<"pivot index :"<<ans<<endl;

    


}