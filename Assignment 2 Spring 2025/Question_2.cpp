#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
    int speed;
    int capacity;
    static int total_deliveries;

public:
    Vehicle(string n, int s, int c) : name(n), speed(s), capacity(c) { total_deliveries++; }
    virtual void deliver(int package_id, string urgency, string destination) {
        cout << name << " is delivering package " << package_id << " with " << urgency << " urgency to " << destination << "...\n";
    }
    virtual void calculate_route() {
        cout << name << " is calculating the optimal route...\n";
    }
    virtual void estimate_delivery_time() {
        cout << name << " is estimating delivery time...\n";
    }
    bool operator==(const Vehicle &v) {
        return (speed == v.speed && capacity == v.capacity);
    }
    friend void resolve_conflict(Vehicle &v1, Vehicle &v2);
};

int Vehicle::total_deliveries = 0;

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip() : Vehicle("Ramzan TimeShip", 300, 500) {}
    void deliver(int package_id, string urgency, string destination) override {
        cout << name << " is validating historical accuracy before delivering package " << package_id << " to " << destination << " with " << urgency << " urgency!\n";
    }
};

class RamzanDrone : public Vehicle {
public:
    RamzanDrone() : Vehicle("Ramzan Drone", 150, 50) {}
    void deliver(int package_id, string urgency, string destination) override {
        cout << name << " is activating high-speed mode to ensure package " << package_id << " reaches " << destination << " in time for " << urgency << "!\n";
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod() : Vehicle("Ramzan HyperPod", 200, 1000) {}
    void deliver(int package_id, string urgency, string destination) override {
        cout << name << " is navigating underground tunnels to deliver package " << package_id << " to " << destination << " with " << urgency << " urgency efficiently!\n";
    }
};

void resolve_conflict(Vehicle &v1, Vehicle &v2) {
    cout << "Conflict detected between " << v1.name << " and " << v2.name << "! Determining the best delivery option...\n";
    if (v1.speed > v2.speed)
        cout << v1.name << " is assigned higher priority due to faster speed.\n";
    else
        cout << v2.name << " is assigned higher priority due to better efficiency.\n";
}

void command(string action, int package_id) {
    cout << "Operator command received: " << action << " package " << package_id << "\n";
}
void command(string action, int package_id, string urgency) {
    cout << "Operator command received: " << action << " package " << package_id << " with " << urgency << " urgency\n";
}

int main() {
    cout << "Huzaifa Nadeem"<<endl;
	cout << "24K-0533"<<endl;
	cout << "BCS-2F"<<endl<<endl;
    
    RamzanTimeShip timeShip;
    RamzanDrone drone;
    RamzanHyperPod hyperPod;
    
    cout << "Ramzan Box Delivery System initializing...\n\n";
    
    command("Deliver", 101);
    command("Deliver", 102, "Sehri");
    
    timeShip.deliver(101, "Normal", "Karachi");
    drone.deliver(102, "Iftar", "Lahore");
    hyperPod.deliver(103, "Sehri", "Islamabad");
    
    cout << "\nResolving delivery conflicts...\n";
    resolve_conflict(drone, hyperPod);
    resolve_conflict(timeShip, drone);
    
    cout << "\nAll deliveries scheduled successfully. Have a blessed Ramzan!\n";
    
    return 0;
}
