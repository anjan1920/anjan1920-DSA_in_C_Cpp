#include<iostream>
#include "Bird.h"  


using namespace std;



void bird_function(Bird *obj){

    obj->eat();
    obj->fly();

}

int main(){

    Bird* my_bird = new Dove();
    bird_function(my_bird);
    //Dove *ob = new Dove();
    //ob->eat(); cant use the private member of the class --> Abstraction of the subclass 



}