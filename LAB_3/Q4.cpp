#include <iostream>

using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    
    Angle() : degrees(0), minutes(0.0), direction('N') {}

    void getAngle() {
        string type;
        
        while (true) {
            cout << "Enter type (latitude/longitude): ";
            cin >> type;
            for (char &c : type) c = tolower(c);  
            if (type == "latitude" || type == "longitude") break;
            cout << "Invalid type. Please enter 'latitude' or 'longitude'.\n";
        }

        int maxDegrees = (type == "latitude") ? 90 : 180;

        while (true) {
            cout << "Enter degrees (0-" << maxDegrees << "): ";
            cin >> degrees;
            if (cin.fail() || degrees < 0 || degrees > maxDegrees) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a valid degree range.\n";
            } else break;
        }

        cin.clear();
        cin.ignore(10000, '\n'); 

        while (true) {
            cout << "Enter minutes (0-59.9): ";
            cin >> minutes;
            if (cin.fail() || minutes < 0 || minutes >= 60) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a value between 0 and 59.9.\n";
            } else break;
        }

        while (true) {
            cout << "Enter direction (N/S for latitude, E/W for longitude): ";
            cin >> direction;
            direction = toupper(direction); 
            if ((type == "latitude" && (direction == 'N' || direction == 'S')) ||
                (type == "longitude" && (direction == 'E' || direction == 'W')))
                break;
            cout << "Invalid direction. Please enter a valid direction based on type.\n";
        }
    }

    void displayAngle() const {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle a1;
    cout << "Initialized angle: ";
    a1.displayAngle();

    while (true) {
        Angle userAngle;
        userAngle.getAngle();
        cout << "You entered: ";
        userAngle.displayAngle();

        char choice;
        cout << "Do you want to enter another angle? (y/n): ";
        cin >> choice;
        if (tolower(choice) == 'n') break;
    }

    return 0;
}
