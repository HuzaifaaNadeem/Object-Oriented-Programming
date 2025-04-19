#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
    double price;

public:
    Vehicle(string n, double p) : name(n), price(p) {}

    virtual double getRate() const = 0;
    virtual void show() const = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string n, double p) : Vehicle(n, p) {}

    double getRate() const override {
        return price;
    }

    void show() const override {
        cout << "Car: " << name << endl;
        cout << "Rate: $" << price << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string n, double p) : Vehicle(n, p) {}

    double getRate() const override {
        return price;
    }

    void show() const override {
        cout << "Bike: " << name << endl;
        cout << "Rate: $" << price << endl;
    }
};

int main() {
    Vehicle* rentals[2];

    rentals[0] = new Car("Corolla", 60.0);
    rentals[1] = new Bike("Honda 125", 20.0);

    cout << "Available Vehicles" << endl;
    for (int i = 0; i < 2; ++i) {
        rentals[i]->show();
        cout << "Daily Rent: $" << rentals[i]->getRate() << endl << endl;
    }

    for (int i = 0; i < 2; ++i)
        delete rentals[i];

    return 0;
}

