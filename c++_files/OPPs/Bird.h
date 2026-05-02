// Bird.h
#ifndef BIRD_H
#define BIRD_H

#include <iostream>
using namespace std;

class Bird {
public:
    virtual void fly() = 0;
    virtual void eat() = 0;
};

class Dove : public Bird {
private:
    void fly() override {
        cout << "Dove flying ..." << endl;
    }
    void eat() override {
        cout << "Dove eating..." << endl;
    }
};

class Eagle : public Bird {
private:
    void fly() override {
        cout << "Eagle flying faster..." << endl;
    }
    void eat() override {
        cout << "Eagle eating..." << endl;
    }
};

#endif // BIRD_H
