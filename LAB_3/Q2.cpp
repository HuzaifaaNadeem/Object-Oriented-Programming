#include <iostream>
#include <conio.h>

using namespace std;

class tollBooth {
private:
    unsigned int totalCars;
    double totalCash;

public:
    tollBooth() {
        totalCars = 0;
        totalCash = 0.0;
    }

    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    void nopayCar() {
        totalCars++;
    }

    void display() {
        
        cout << endl << "Total Cars: " << totalCars << endl;
        cout << "Total Cash Collected: $" << totalCash << endl;
        
    }
};

int main() {
    tollBooth booth;

    while (true) {
        cout << "Press 'p' for a paying car, 'n' for a non-paying car, or 'Esc' to quit and display totals: ";
		char key = _getch();

        if (key == 27) {
            booth.display();
            break;
        }

        if (key == 'p' || key == 'P') {
            booth.payingCar();
            cout << "\n\nPaying car added!\n" << endl;
        }
        
        else if (key == 'n' || key == 'N') {
            booth.nopayCar();
            cout << "\n\nNon-paying car added!\n" << endl;
        }

        else {
            cout << "\n\nInvalid input. Please press 'p' or 'n' to count cars, or 'Esc' to quit.\n\n";
        }
    }

    return 0;
}

