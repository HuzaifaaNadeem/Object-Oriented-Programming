#include <iostream>
using namespace std;

class Square {
private:
    float sideLength;
    float area;
    static float allareas;

public:
    Square() : sideLength(0.0), area(0.0) {}

    Square(float side) : sideLength(side), area(0.0) {}

    void calculate_area() {
        area = sideLength * sideLength;
        allareas += area;
    }

    float get_sideLength() const {
        return sideLength;
    }

    float get_area() const {
        return area;
    }

    static float get_allareas() {
        return allareas;
    }

    void set_sideLength(float side) {
        sideLength = side;
    }

    void set_area(float a) {
        area = a;
    }
};

float Square::allareas = 0.0;

int main() {
    Square square1(4.0);
    Square square2(5.0);
    Square square3(6.0);
    
    square1.calculate_area();
    cout << "Square 1: Area: " << square1.get_area() << ", Total of all Areas: " << Square::get_allareas() << endl;
    
    square2.calculate_area();
    cout << "Square 2: Area: " << square2.get_area() << ", Total of all Areas: " << Square::get_allareas() << endl;
    
    square3.calculate_area();
    cout << "Square 3: Area: " << square3.get_area() << ", Total of all Areas: " << Square::get_allareas() << endl;
    
    return 0;
}
