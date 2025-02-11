#include <iostream>
using namespace std;

class Car {
private:
    int id;
    string name;
    int manufactureYear;
    bool rented;

public:
    Car() : rented(false) {}

    Car(int carID, string carName, int year) 
        : id(carID), name(carName), manufactureYear(year), rented(false) {}

    void rent() {
        if (!rented) {
            rented = true;
            cout << "Car " << name << " (ID: " << id << ") rented." << endl;
        } else {
            cout << name << " is already rented." << endl;
        }
    }

    void returnCar() {
        if (rented) {
            rented = false;
            cout << "Car " << name << " (ID: " << id << ") returned." << endl;
        } else {
            cout << name << " is already available." << endl;
        }
    }

    bool isVintage() const {
        return manufactureYear < 2000;
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | Year: " << manufactureYear;
        cout << " | Status: " << (rented ? "Rented" : "Available") << endl;
    }
    
    string getname() const{
	   return name;
	}
};

int main() {
    Car car1(101, "Toyota Corolla", 1998);
    Car car2(102, "Honda Civic", 2015);
    Car car3(103, "Ford Mustang", 1967);

    car1.display();
    car2.display();
    car3.display();

    car1.rent();
    car2.rent();
    car1.display();
    car2.display();
    
    car1.returnCar();
    car1.display();
    
    cout << car3.getname() << " is vintage: " << (car3.isVintage() ? "Yes" : "No") << endl;
    
    return 0;
}

