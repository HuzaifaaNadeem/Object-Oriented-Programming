#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool active;
    int level;

public:
    LightBulb() : active(false), level(0) {}

    void turnOn() override {
        active = true;
        level = 75;
    }

    void turnOff() override {
        active = false;
        level = 0;
    }

    string getStatus() const override {
        if (active) {
            return "Light is ON | Brightness: " + to_string(level);
        } else {
            return "Light is OFF";
        }
    }
};

class Thermostat : public SmartDevice {
private:
    bool active;
    double temp;

public:
    Thermostat() : active(false), temp(0.0) {}

    void turnOn() override {
        active = true;
        temp = 24.5;
    }

    void turnOff() override {
        active = false;
        temp = 0.0;
    }

    string getStatus() const override {
        if (active) {
            return "Thermostat is ON | Temperature: " + to_string(temp);
        } else {
            return "Thermostat is OFF";
        }
    }
};

int main() {
    SmartDevice* devices[2];
    devices[0] = new LightBulb();
    devices[1] = new Thermostat();

    for (int i = 0; i < 2; ++i)
        devices[i]->turnOn();

    cout << "Device Statuses After Turning ON:" << endl;
    for (int i = 0; i < 2; ++i)
        cout << devices[i]->getStatus() << endl;

    for (int i = 0; i < 2; ++i) {
        devices[i]->turnOff();
        delete devices[i];
    }

    return 0;
}
