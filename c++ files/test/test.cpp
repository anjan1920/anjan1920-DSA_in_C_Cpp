#include<iostream>
using namespace std;

class A{
    int privateA = 10;
    float a = 50;
    void showPrivate(){
        cout<<"inside private:"<<privateA<<endl;
    }

public:
    int a = 10;
    void show(){
        cout<<"public a:"<<a<<endl;
    }
    void showPrivate_byPUblic(){
        cout<<"::"<<privateA<<endl;
        privateA+=10;
        cout<<"PrivateA value changed"<<endl;
    }
    

};
int main(){
    A *obj = new A();
    obj->show();
   // obj->privateA = 10;
   obj->a = 20;
   obj->show();
   obj->showPrivate_byPUblic();
   obj->showPrivate_byPUblic();

   A obj01;
   obj01.a = 10;
   obj01.show();


}