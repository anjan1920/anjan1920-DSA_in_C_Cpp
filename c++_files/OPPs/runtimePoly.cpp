#include<iostream>
using namespace std;

class Parent {
public:
    virtual void show() {
        cout << "Parent show()\n";
    }
    void sleep(){
        cout<<"parent sleep\n";
    }
};

class Child : public Parent {
public:
    void show() override {
        cout << "Child show()\n";
    }
    void sleep(){
        cout<<"Child sleep.\n";
    }
};

int main() {
    

    //here its the compile time poly 
   Parent *myob1 = new Parent();
   myob1->show();
   Child *myob2 = new Child();
   myob2->show();

   cout<<"--------\n"<<endl;

   //now the runtime poly
   Parent* ptr;// Super class pointer
    Child c;//sub class oobj
    Parent p;
    ptr = &c;
    ptr->show();  //  Output: Child show()
    //switch the pointer
    ptr = &p;
    ptr->show();
    cout<<"--------"<<endl;
    c.sleep();
    ptr->sleep();
    ptr = &c;
    ptr->sleep();

   

}
