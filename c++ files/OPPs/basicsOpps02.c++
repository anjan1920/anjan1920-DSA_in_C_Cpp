#include <iostream>
using namespace std;

class Secret {
private:
    int data;

    //  Private constructor
    Secret(int val) {
        data = val;
    }

    // Declare friend class
    friend class Factory;
};

class Factory {
public:
    //  Can access private constructor
    Secret createSecret(int val) {
        return Secret(val);
    }
};
int main() {
    // Secret s(10);  Error: constructor is private

    Factory f;
    Secret s = f.createSecret(42);  //  Created using friend class

    cout << "Secret created!" << endl;
    return 0;
}
