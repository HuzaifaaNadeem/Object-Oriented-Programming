#include <iostream>
using namespace std;


bool validate_age(int age) {
    if (age < 0 || age > 120) {
        cout << "Error: InvalidValueException - Age cannot be negative or exceed 120." << endl;
        return false;
    }
    return true;
}

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;

    if (validate_age(age)) {
        cout << "Valid age entered: " << age << endl;
    }

    return 0;
}

