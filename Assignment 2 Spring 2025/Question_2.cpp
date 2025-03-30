#include <iostream>

using namespace std;

class Vehicle {
protected:
    string name;
    int speed;
    int capacity;

public:
    Vehicle(string n, int s, int c) : name(n), speed(s), capacity(c) {}
    virtual void deliver(int weight, string urgency, string destination) {
        cout << name << " is delivering a " << weight << "kg package with " << urgency << " urgency to " << destination << "...\n";
    }
    virtual void efficiency_metrics() {
        cout << "Calculating efficiency metrics for " << name << "...\n";
    }
    bool operator>(const Vehicle &v) {
        return speed > v.speed;
    }
    friend void resolve_conflict(Vehicle &v1, Vehicle &v2);
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip() : Vehicle("Ramzan TimeShip", 300, 500) {}
    void deliver(int weight, string urgency, string destination) override {
        cout << name << " is traveling through time to swiftly deliver a " << weight << "kg package with " << urgency << " urgency to " << destination << "!\n";
    }
};

class RamzanDrone : public Vehicle {
public:
    RamzanDrone() : Vehicle("Ramzan Drone", 150, 50) {}
    void deliver(int weight, string urgency, string destination) override {
        cout << name << " is soaring through the sky to quickly deliver a " << weight << "kg package with " << urgency << " urgency to " << destination << "!\n";
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod() : Vehicle("Ramzan HyperPod", 200, 1000) {}
    void deliver(int weight, string urgency, string destination) override {
        cout << name << " is using hyperloop speed to get a " << weight << "kg package to " << destination << " with " << urgency << " urgency!\n";
    }
};

void resolve_conflict(Vehicle &v1, Vehicle &v2) {
    cout << "Oh no! A scheduling conflict between " << v1.name << " and " << v2.name << "! Let's see who gets priority...\n";
    if (v1 > v2)
        cout << v1.name << " is assigned higher priority for this delivery.\n";
    else
        cout << v2.name << " is assigned higher priority for this delivery.\n";
}

int main() {
    RamzanTimeShip timeShip;
    RamzanDrone drone;
    RamzanHyperPod hyperPod;
    
    cout << "Ramzan delivery system initializing...\n\n";
    
    timeShip.deliver(10, "Sehri", "Karachi");
    drone.deliver(5, "Iftar", "Lahore");
    hyperPod.deliver(50, "Normal", "Islamabad");
    
    cout << "\nResolving delivery conflicts...\n";
    resolve_conflict(drone, hyperPod);
    resolve_conflict(timeShip, drone);
    
    cout << "\nAll deliveries scheduled successfully. Have a blessed Ramzan!\n";
    
    return 0;
}
