#include <iostream>
#include <string>
using namespace std;

class User {
public:
    string name;
    int age;
    string license_type;
    string contact;
    int user_id;

    User(string name, int age, string license_type, string contact, int user_id)
        : name(name), age(age), license_type(license_type), contact(contact), user_id(user_id) {}

    void updateDetails(string new_name, int new_age, string new_license, string new_contact) {
        name = new_name;
        age = new_age;
        license_type = new_license;
        contact = new_contact;
    }
};

class Vehicle {
public:
    string model;
    double rental_price;
    string required_license;

    Vehicle(string model, double rental_price, string required_license)
        : model(model), rental_price(rental_price), required_license(required_license) {}

    bool isEligible(string user_license) {
        return user_license == required_license;
    }
};

class RentalSystem {
private:
    User* users[100];
    Vehicle* vehicles[100];
    int user_count = 0;
    int vehicle_count = 0;
public:
    ~RentalSystem() {
        for (int i = 0; i < vehicle_count; i++) {
            delete vehicles[i];
        }
        for (int i = 0; i < user_count; i++) {
            delete users[i];
        }
    }

    void registerUser(string name, int age, string license, string contact, int user_id) {
        if (user_count < 100) {
            users[user_count++] = new User(name, age, license, contact, user_id);
        }
    }

    void updateUser(int user_id, string new_name, int new_age, string new_license, string new_contact) {
        for (int i = 0; i < user_count; i++) {
            if (users[i]->user_id == user_id) {
                users[i]->updateDetails(new_name, new_age, new_license, new_contact);
                return;
            }
        }
        cout << "User not found!" << endl;
    }

    void addVehicle(string model, double price, string license_required) {
        if (vehicle_count < 100) {
            vehicles[vehicle_count++] = new Vehicle(model, price, license_required);
        }
    }

    void displayVehicles() {
        for (int i = 0; i < vehicle_count; i++) {
            cout << i + 1 << ". Model: " << vehicles[i]->model << ", Price: " << vehicles[i]->rental_price
                 << ", License Required: " << vehicles[i]->required_license << endl;
        }
    }

    void rentVehicle(int user_id, int vehicle_index) {
        if (vehicle_index < 1 || vehicle_index > vehicle_count) {
            cout << "Invalid vehicle selection!" << endl;
            return;
        }
        for (int i = 0; i < user_count; i++) {
            if (users[i]->user_id == user_id) {
                if (vehicles[vehicle_index - 1]->isEligible(users[i]->license_type)) {
                    cout << "Vehicle rented successfully! Model: " << vehicles[vehicle_index - 1]->model << endl;
                } else {
                    cout << "You are not eligible to rent this vehicle!" << endl;
                }
                return;
            }
        }
        cout << "User not found!" << endl;
    }
};

int main() {
    cout << "Huzaifa Nadeem"<<endl;
	cout << "24K-0533"<<endl;
	cout << "BCS-2F"<<endl<<endl;
	
	RentalSystem system;
    system.registerUser("Ali", 25, "Full", "123-456-7890", 1);
    system.registerUser("Bhavesh", 20, "Learner", "987-654-3210", 2);

    system.addVehicle("Sedan", 50.0, "Full");
    system.addVehicle("Scooter", 20.0, "Learner");

    cout << "Available Vehicles:" << endl;
    system.displayVehicles();

    cout << "\nUser Renting Attempts:" << endl;
    system.rentVehicle(1, 1); 
    system.rentVehicle(2, 1); 
    system.rentVehicle(2, 2); 
    
    return 0;
}
