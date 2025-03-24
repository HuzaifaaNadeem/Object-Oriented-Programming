#include <iostream>
using namespace std;

class Light;
class Fan;
class Air_Conditioner;
class Security_System;

class User {
private:
    string user_id, user_role;
    int access_level;

public:
    User(string id, string role, int level) : user_id(id), user_role(role), access_level(level) {}

    void show_accessible_devices() const;

    friend class Security_System;
};

class Device {
protected:
    string device_id, device_name;
    double power_usage;

public:
    Device(string id, string name, double power) : device_id(id), device_name(name), power_usage(power) {}

    virtual void power_on() const = 0;

    virtual double compute_power(int hours) const {
        return power_usage * hours;
    }

    friend ostream& operator<<(ostream &out, const Device &device) {
        out << device.device_name << " [ID: " << device.device_id << "]";
        return out;
    }
};

class Light : public Device {
public:
    Light(string id, string name, double power) : Device(id, name, power) {}

    void power_on() const override {
        cout << *this << " turned ON.\n";
    }
};

class Fan : public Device {
private:
    int speed_level;

public:
    Fan(string id, string name, double power, int speed) : Device(id, name, power), speed_level(speed) {}

    void power_on() const override {
        cout << *this << " turned ON at Speed " << speed_level << ".\n";
    }

    double compute_power(int hours) const override {
        return power_usage * speed_level * hours;
    }
};

class Air_Conditioner : public Device {
private:
    int temperature_setting;

public:
    Air_Conditioner(string id, string name, double power, int temp) : Device(id, name, power), temperature_setting(temp) {}

    void power_on() const override {
        cout << *this << " turned ON. Cooling to " << temperature_setting << "°C.\n";
    }

    double compute_power(int hours) const override {
        return (power_usage * hours) * (1 + (25 - temperature_setting) * 0.02);
    }
};

class Security_System : public Device {
public:
    Security_System(string id, string name, double power) : Device(id, name, power) {}

    void power_on() const override {
        cout << *this << " activated.\n";
    }

    double compute_power(int hours) const override {
        return power_usage * hours * 1.5;
    }

    void view_logs(const User &user) const {
        if (user.access_level >= 2) {
            cout << user.user_id << " - Security Logs Accessed:\n";
            cout << "- Intrusion Detected at 3:00 AM\n- System Reset Required\n";
        } else {
            cout << user.user_id << " has no access to security logs.\n";
        }
    }
};

void User::show_accessible_devices() const {
    cout << "User: " << user_id << " - Accessible Devices:\n";
    cout << "- LED Light\n- Ceiling Fan\n- Split AC\n";
    if (access_level >= 2) {
        cout << "- Security System (Restricted Access)\n";
    }
}

int main() {
    User user_admin("U001", "Regular User", 1);
    User user_tech("U002", "Maintenance Staff", 2);

    Light led_light("L001", "LED Light", 10);
    Fan ceiling_fan("F001", "Ceiling Fan", 75, 3);
    Air_Conditioner split_ac("AC001", "Split AC", 1500, 25);
    Security_System home_alarm("S001", "Home Alarm", 100);

    led_light.power_on();
    ceiling_fan.power_on();
    split_ac.power_on();
    home_alarm.power_on();

    cout << "\nPower Consumption:\n";
    cout << "LED Light: " << led_light.compute_power(5) << " Watts\n";
    cout << "Ceiling Fan: " << ceiling_fan.compute_power(3) << " Watts\n";
    cout << "Split AC: " << split_ac.compute_power(6) << " Watts\n";
    cout << "Security System: " << home_alarm.compute_power(24) << " Watts\n\n";

    user_admin.show_accessible_devices();
    home_alarm.view_logs(user_tech);


    return 0;
}
