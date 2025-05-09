#include <iostream>
#include <string>
#include <exception>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

double sqrtApprox(double value) {
    double x = value;
    double y = 1;
    double e = 0.00001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = value / x;
    }
    return x;
}

double sqrt(int x) {
    if (x < 0) throw NegativeNumberException();
    return sqrtApprox(static_cast<double>(x));
}

double sqrt(double x) {
    if (x < 0) throw NegativeNumberException();
    return sqrtApprox(x);
}

double sqrt(string x) {
    throw InvalidTypeException();
}

int main() {
    try {
        cout << "Result: " << sqrt(-4) << endl;
    } catch (const exception& e) {
        cout << "sqrt(-4): " << e.what() << endl;
    }

    try {
        cout << "Result: " << sqrt(string("hello")) << endl;
    } catch (const exception& e) {
        cout << "sqrt(\"hello\"): " << e.what() << endl;
    }

    return 0;
}
