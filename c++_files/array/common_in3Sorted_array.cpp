//common element in three sorted array
#include<iostream>
#include<vector>
#include<set>

//we are using sets , its dont take duplicate value
//set.insert(2)//input
//printing set--  for( int i: set){ cout<<i<<" "; }
//     
//    
//    
using namespace std;


int main(){
   vector<int > a={1,2,3,4,5,6,8,10};
   vector<int > b={2,3,4,5,8,9};
   vector<int > c={5,8,10,20,30};
   
   int n1=a.size(), n2=b.size() , n3=c.size();
  
   //define the set
   set<int>my_set;

   
   int i,j,k ;
   i= j= k=0;//3 pointer for 3 array

   while (i<n1 && j<n2 && k<n3 ){
    //break the loop when any of the array traverse is completed

    if( a[i] == b[j] && b[j]== c[k] ){

        my_set.insert(a[i]);

        i++;
        j++;
        k++;
    }else if( a[i]< b[j] ){

         i++;
    }else if( b[j] < c[k]){
        j++;
    }else{

        k++;
    }



   }



    //printing set
    for( int i: my_set){

        cout<<i<<" ";
    }
    //T.n =O(max(n1,n2,n3))








}



