#include <iostream>
#include <exception>
using namespace std;


class InvalidValueException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validate_age(int age) {
    if (age < 0 || age > 120) {
        throw InvalidValueException();
    }
}

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;

    try {
        validate_age(age);
        cout << "Valid age entered: " << age << endl;
    } catch (const InvalidValueException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
