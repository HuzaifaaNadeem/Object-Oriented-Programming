#include <iostream>
using namespace std;

class Vehicle {
private:
    static int total_deliveries;

protected:
    int speed;
    string vehicle_id;
    int capacity;
    int energy_efficiency;
    double efficiency;

public:
    Vehicle(string id, int spd, int cap, int eng) {
        speed = spd;
        capacity = cap;
        energy_efficiency = eng;
        vehicle_id = id;
        total_deliveries++;
    }

    Vehicle() { total_deliveries++; }

    Vehicle(string id) {
        vehicle_id = id;
        total_deliveries++;
    }

    static int get_total_deliveries() {
        return total_deliveries;
    }

    virtual float estimated_delivery_time(float distance) = 0;
    virtual void optimal_delivery_route() = 0;

    friend bool operator==(Vehicle &v1, Vehicle &v2) {
        return (v1.speed == v2.speed && v1.capacity == v2.capacity && v1.energy_efficiency == v2.energy_efficiency);
    }

    virtual void command(string cmd, string id) {}
    virtual void command(string cmd, string id, string urgency) {}

    friend bool resolve_conflict(Vehicle &v1, Vehicle &v2);
};

int Vehicle::total_deliveries = 0;

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id) : Vehicle(id) { efficiency = 92; }
    RamzanDrone(string id, int spd, int cap, int eng) : Vehicle(id, spd + 3, cap + 8, eng + 12) {}

    float estimated_delivery_time(float distance) override {
        cout << "\n[Ramzan Drone] " << vehicle_id << " - Calculating time for aerial route..." << endl;
        return distance / speed;
    }

    void optimal_delivery_route() override {
        cout << "[Ramzan Drone] Aerial delivery route selected." << endl;
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id) : Vehicle(id) { efficiency = 87; }
    RamzanTimeShip(string id, int spd, int cap, int eng) : Vehicle(id, spd + 7, cap + 18, eng + 25) {}

    float estimated_delivery_time(float distance) override {
        cout << "\n[Ramzan Time Ship] " << vehicle_id << " - Ensuring time-sensitive delivery..." << endl;
        return distance / speed;
    }

    void optimal_delivery_route() override {
        cout << "[Ramzan Time Ship] Deciding optimal route for historical delivery." << endl;
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id) : Vehicle(id) { efficiency = 97; }
    RamzanHyperPod(string id, int spd, int cap, int eng) : Vehicle(id, spd + 10, cap + 25, eng + 40) {}

    float estimated_delivery_time(float distance) override {
        cout << "\n[Ramzan HyperPod] " << vehicle_id << " - Calculating ETA via tunnel navigation..." << endl;
        return distance / speed;
    }

    void optimal_delivery_route() override {
        cout << "[Ramzan HyperPod] Estimating bulk transport time." << endl;
    }
};

bool resolve_conflict(Vehicle &v1, Vehicle &v2) {
    cout << "\n[Conflict Resolution] Between " << v1.vehicle_id << " and " << v2.vehicle_id << "..." << endl;
    if (v1.efficiency > v2.efficiency) {
        cout << "[Decision] " << v1.vehicle_id << " is chosen for the delivery." << endl;
        return true;
    } else {
        cout << "[Decision] " << v2.vehicle_id << " is chosen for the delivery." << endl;
        return false;
    }
}

int main() {
    RamzanDrone drone("DRONE-1001", 108, 165, 220);
    RamzanTimeShip ship("TIMESHIP-005", 215, 530, 2550);
    RamzanHyperPod pod("HYPERPOD-XV", 120, 190, 255);

    float distance = 1300.0;
    cout << "\n================ DELIVERY TIME ESTIMATES ================" << endl;
    cout << "Drone: " << drone.estimated_delivery_time(distance) << " hours" << endl;
    cout << "Time Ship: " << ship.estimated_delivery_time(distance) << " hours" << endl;
    cout << "HyperPod: " << pod.estimated_delivery_time(distance) << " hours" << endl;
    
    cout << "\n================ OPTIMAL DELIVERY ROUTES ================" << endl;
    drone.optimal_delivery_route();
    ship.optimal_delivery_route();
    pod.optimal_delivery_route();

    cout << "\n================ COMMAND EXECUTION ================" << endl;
    drone.command("Deliver", "128", "high");
    ship.command("Deliver", "459", "low");
    pod.command("Pickup", "138");

    if (drone == pod) {
        resolve_conflict(drone, pod);
    }

    cout << "\n================ SUMMARY ================" << endl;
    cout << "Total active deliveries: " << Vehicle::get_total_deliveries() << endl;

    return 0;
}
