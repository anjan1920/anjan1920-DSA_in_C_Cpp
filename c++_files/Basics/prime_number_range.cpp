#include<iostream>
using namespace std;
//T.n = O(n^2) // not a good approach when upper limit is high ~10^4,5

bool isPrime(int num){
    bool flag = true;
    for(int i =2 ;i<num ;i ++){
        if( num %i == 0){
            flag = false;
            return flag;
        }else{
            continue;
        }
    }
    return flag;
}
int main(){
    int s,e ;
    int count  = 0;
    cout<<"Enter upper and lower bound :";
    cin>>s>>e;
    cout<<"Upper bound:"<<s<<" Lower bound :"<<e<<endl;

    if(s<0 || e<0 ){
        cout<<"Invalid range (-ve value)";
        return 0;
    }else if( s>e){
        cout<<"Range invalid lower > upper !!";
        return 0;
    }else{
        if(s == 0 || s == 1)
        s = 2;
    
    for(int  i = s ;i<e ;i ++){
        bool ans = isPrime(i);
        if(ans){
            cout<<i<<" ";
            count++;
        }else{
            continue;
        }
        
    }
    }
    cout<<"\n total prime number count :"<<count<<endl;
    
return 0;

}