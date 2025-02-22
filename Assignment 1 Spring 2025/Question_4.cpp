#include <iostream>
using namespace std;

class BusCard {
private:
    bool is_active;
public:
    BusCard() : is_active(true) {}
    void activate() { is_active = true; }
    void deactivate() { is_active = false; }
    bool tap_card(int student_id) {
        if (!is_active) return false;
        cout << "Attendance recorded for student ID: " << student_id << endl;
        return true;
    }
};

class Stop {
public:
    string location;
    Stop() : location("") {}
    Stop(string loc) : location(loc) {}
};

class Route {
private:
    Stop stops[10];
    int stop_count;
public:
    Route() : stop_count(0) {}
    void add_stop(string loc) {
        if (stop_count < 10) {
            stops[stop_count++] = Stop(loc);
            cout << "Stop added: " << loc << endl;
        }
    }
};

class Student {
private:
    int id;
    string name;
    BusCard *card;
    Stop *assigned_stop;
public:
    Student(int student_id, string student_name) : id(student_id), name(student_name) {
        card = new BusCard();
    }
    ~Student() { delete card; }
    void register_for_transport(Stop *stop) { assigned_stop = stop; }
    void activate_card() { card->activate(); }
    void tap_card() { card->tap_card(id); }
};

class Bus {
public:
    string bus_id;
    Route *assigned_route;
    Bus(string id, Route *route) : bus_id(id), assigned_route(route) {}
};

class Attendance {
private:
    int student_ids[100];
    string dates[100];
    int record_count;
public:
    Attendance() : record_count(0) {}
    void mark_attendance(int student_id, string date) {
        if (record_count < 100) {
            student_ids[record_count] = student_id;
            dates[record_count] = date;
            record_count++;
        }
    }
};

class TransportSystem {
private:
    Student *students[100];
    int student_count;
    Bus *buses[50];
    int bus_count;
    Route *routes[20];
    int route_count;
public:
    TransportSystem() : student_count(0), bus_count(0), route_count(0) {}
    void register_student(int id, string name) {
        if (student_count < 100) {
            students[student_count++] = new Student(id, name);
            cout << "Student registered: " << name << " (ID: " << id << ")" << endl;
        }
    }
    void manage_routes(Route *route) {
        if (route_count < 20) {
            routes[route_count++] = route;
            cout << "Route added to the system." << endl;
        }
    }
};

int main() {
    cout << "Huzaifa Nadeem"<<endl;
	cout << "24K-0533"<<endl;
	cout << "BCS-2F"<<endl<<endl;
	
	TransportSystem system;
    system.register_student(533, "Huzaifa Nadeem");
    Route *route = new Route();
    route->add_stop("FAST University");
    route->add_stop("Johar Mor");
    route->add_stop("Gulshan Chowrangi");
    route->add_stop("NIPA");
    route->add_stop("Maskan");
    route->add_stop("Dhoraji");
    route->add_stop("Gulistan-e-Johar Block 15");
    system.manage_routes(route);
    Bus *bus = new Bus("5B", route);
    cout << "Bus assigned to route successfully. Bus ID: " << bus->bus_id << endl;
    cout << "Transport System Initialized Successfully!" << endl;
    delete bus;
    delete route;
    return 0;
}
