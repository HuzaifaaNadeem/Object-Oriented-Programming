#include <iostream>
using namespace std;


class Activity {
public:
    virtual double calculate_calories_burned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double* distance_km;
    double* time_min;    

public:
    Running(double dist, double time) {
        distance_km = new double(dist);
        time_min = new double(time);
    }

    ~Running() {
        delete distance_km;
        delete time_min;
    }

    double calculate_calories_burned() override {
        double speed_kmph = (*distance_km) / (*time_min / 60.0); 
        double calories = (*distance_km) * 60; 
        cout << "Running Speed: " << speed_kmph << " km/h" << endl;
        return calories;
    }
};


class Cycling : public Activity {
private:
    double* speed_kmph; 
    double* time_hr;    

public:
    Cycling(double speed, double time) {
        speed_kmph = new double(speed);
        time_hr = new double(time);
    }

    ~Cycling() {
        delete speed_kmph;
        delete time_hr;
    }

    double calculate_calories_burned() override {
        double calories = (*speed_kmph) * (*time_hr) * 30; 
        return calories;
    }
};


int main() {
    Activity* run = new Running(5.0, 30.0);      
    Activity* cycle = new Cycling(20.0, 1.0);    

    cout << "\n--- Running Activity ---" << endl;
    cout << "Calories Burned: " << run->calculate_calories_burned() << " kcal\n";

    cout << "\n--- Cycling Activity ---" << endl;
    cout << "Calories Burned: " << cycle->calculate_calories_burned() << " kcal\n";

    delete run;
    delete cycle;

    return 0;
}
