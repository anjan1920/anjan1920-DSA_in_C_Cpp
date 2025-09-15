#include <iostream>
#include <cstring>  // Required for strcpy 
using namespace std;

class Student {
private:
    int age;
    char* name;  // Dynamic memory 

public:
    // 1️ Default Constructor
    Student() {
        age = 0;
        name = new char[1];
        name[0] = '\0';
        cout << "Default Constructor Called\n";
    }

    // 2️ Parameterized Constructor
    Student(int a, const char* n) {
        age = a;
        name = new char[strlen(n) + 1];// new memory in the heap.
        strcpy(name, n);//copy n to name
        cout << "Parameterized Constructor Called\n";
    }

    // 3️ Shallow Copy Constructor (By Default)
    Student(const Student& s) {  // Shallow Copy Constructor
        age = s.age;
        name = s.name;
    }
    
    //Deep copying is needed only for dynamically allocated data (like name), not for simple data types.
    Student(const Student& s, bool value) {  // Deep Copy Constructor
        age = s.age;  // Simple data copy (stored in stack)
        name = new char[strlen(s.name) + 1];  //  New Heap Memory Allocation
        strcpy(name, s.name);  // Copy the string content
    }
    

    // 5️ Destructor (Memory Cleanup)
    ~Student() {
        delete[] name;  //  Free dynamically allocated memory
        cout << "Destructor Called\n";
    }

    // 6️ Using `this` Pointer
    void setAge(int age) {
        this->age = age;  // `this` differentiates member variable from parameter
    }

    void show() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

//  Main function to demonstrate stack & heap allocation
int main() {
    cout << "\nStack Object:\n";
    Student s1(20, "Anjan");  //  Stack Object (auto cleanup)
    s1.show();

    cout << "\neap Object:\n";
    Student* s2 = new Student(22, "Rohit");  //  Heap Object (manual cleanup)
    s2->show();
    delete s2;  // Must use delete to avoid memory leak

    cout << "\n Shallow Copy Example:\n";
    Student s3 = s1;  // Calls default shallow copy constructor
    s3.show();

    cout << "\n Deep Copy Example:\n";
    Student s4(s1, true);  // Calls deep copy constructor
    s4.show();

    cout << " Destructor Demonstration:\n";
    return 0;  // Stack objects (s1, s3, s4) are automatically destroyed
}
