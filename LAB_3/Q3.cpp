#include <iostream>

using namespace std;

class Object {
private:
    static int objectCount;
    int id;

public:
    Object() {
        id = ++objectCount;
    }

    void displayID() const {
        cout << "This is object number " << id << endl;
    }
};

int Object::objectCount = 0;

int main() {
    Object product1;
    Object product2;
    Object product3;

    product1.displayID();
    product2.displayID();
    product3.displayID();

    return 0;
}

