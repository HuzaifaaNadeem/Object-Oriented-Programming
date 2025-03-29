#include <iostream>
using namespace std;

class Person {
private:
    const int id;
    string name;
public:
    Person(int id, string name) : id(id), name(name) {}
    virtual void pay_fee() = 0;
    virtual ~Person() {}
    
    int getId() const { return id; }
    string getName() const { return name; }
    void setName(string newName) { name = newName; }
};

class Student : public Person {
public:
    Student(int id, string name) : Person(id, name) {}
    void pay_fee() override {
        cout << "Student " << getName() << " paid semester fee.\n";
    }
};

class Teacher : public Person {
public:
    Teacher(int id, string name) : Person(id, name) {}
    void pay_fee() override {
        cout << "Teacher " << getName() << " paid monthly fee.\n";
    }
};

class StaffMember : public Person {
public:
    StaffMember(int id, string name) : Person(id, name) {}
    void pay_fee() override {
        cout << "Staff Member " << getName() << " paid monthly fee.\n";
    }
};

class Stop {
public:
    string location;
    Stop(string loc = "") : location(loc) {}
};

class Route {
private:
    Stop* stops;
    int stop_count;
    int capacity;
public:
    Route(int cap = 10) : stop_count(0), capacity(cap) {
        stops = new Stop[capacity];
    }
    void add_stop(string loc) {
        if (stop_count < capacity) {
            stops[stop_count++] = Stop(loc);
        }
    }
    bool operator==(const Route &other) const {
        if (stop_count != other.stop_count) return false;
        for (int i = 0; i < stop_count; i++) {
            if (stops[i].location != other.stops[i].location) return false;
        }
        return true;
    }
    ~Route() {
        delete[] stops;
    }
};

class Bus {
public:
    string bus_id;
    Route* assigned_route;
    Bus(string id, Route* route) : bus_id(id), assigned_route(route) {}
};

class TransportSystem {
private:
    Person** users;
    int user_count;
    int user_capacity;
    Bus** buses;
    int bus_count;
    int bus_capacity;
    Route** routes;
    int route_count;
    int route_capacity;
public:
    TransportSystem(int userCap = 100, int busCap = 50, int routeCap = 20)
        : user_count(0), user_capacity(userCap),
          bus_count(0), bus_capacity(busCap),
          route_count(0), route_capacity(routeCap) {
        users = new Person*[user_capacity];
        buses = new Bus*[bus_capacity];
        routes = new Route*[route_capacity];
    }
    void register_user(Person* p) {
        if (user_count < user_capacity) {
            users[user_count++] = p;
        }
    }
    void add_route(Route* r) {
        if (route_count < route_capacity) {
            routes[route_count++] = r;
        }
    }
    void add_bus(Bus* b) {
        if (bus_count < bus_capacity) {
            buses[bus_count++] = b;
        }
    }
    void collect_semester_fees() {
        for (int i = 0; i < user_count; i++) {
            if (dynamic_cast<Student*>(users[i])) {
                users[i]->pay_fee();
            }
        }
    }
    void collect_monthly_fees() {
        for (int i = 0; i < user_count; i++) {
            if (dynamic_cast<Teacher*>(users[i]) || dynamic_cast<StaffMember*>(users[i])) {
                users[i]->pay_fee();
            }
        }
    }
    ~TransportSystem() {
        for (int i = 0; i < user_count; i++) delete users[i];
        for (int i = 0; i < route_count; i++) delete routes[i];
        for (int i = 0; i < bus_count; i++) delete buses[i];
        delete[] users;
        delete[] routes;
        delete[] buses;
    }
};

int main() {
    TransportSystem system;
    system.register_user(new Student(1, "Huzaifa"));
    system.register_user(new Teacher(2, "Prof. Ali"));
    system.register_user(new StaffMember(3, "Mr. Ahmed"));
    cout << "Collecting semester fees:\n";
    system.collect_semester_fees();
    cout << "Collecting monthly fees:\n";
    system.collect_monthly_fees();
    Route* route1 = new Route();
    route1->add_stop("FAST University");
    route1->add_stop("Johar Mor");
    Route* route2 = new Route();
    route2->add_stop("FAST University");
    route2->add_stop("Johar Mor");
    if (*route1 == *route2) {
        cout << "Routes are equal\n";
    } else {
        cout << "Routes are not equal\n";
    }
    system.add_route(route1);
    system.add_route(route2);
    system.add_bus(new Bus("5B", route1));
    return 0;
}
