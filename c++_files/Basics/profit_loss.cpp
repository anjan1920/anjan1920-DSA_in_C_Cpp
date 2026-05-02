//profit loss
#include<iostream>
using namespace std;
int main(){
    int cp,sp;
    cout<<"Enter cost price:";
    cin>>cp;
    cout<<"Enter sell price:";
    cin>>sp;
    
    float profit = sp - cp;
    float profitPercentage = (profit / cp) * 100;
    
    if(profit>=0){
        cout<<"Your profit is:%"<<profit<<endl;
    }
    else{
    cout<<"Your loss is :%"<<-1*profit<<endl;
    }
    return 0;
}
