#include <iostream>

using namespace std;

class Shape {
protected:
    string color;
    double border_thickness;
public:
    Shape(string color = "black", double border_thickness = 1.0)
        : color(color), border_thickness(border_thickness) {}

    virtual void draw() const = 0;
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
    
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius, string color = "black", double border_thickness = 1.0)
        : Shape(color, border_thickness), radius(radius) {}

    void draw() const override {
        cout << "Drawing a Circle with radius " << radius << "\n";
    }

    double calculate_area() const override {
        return 3.141592653589793 * radius * radius;
    }

    double calculate_perimeter() const override {
        return 2 * 3.141592653589793 * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double width, double height, string color = "black", double border_thickness = 1.0)
        : Shape(color, border_thickness), width(width), height(height) {}

    void draw() const override {
        cout << "Drawing a Rectangle with width " << width << " and height " << height << "\n";
    }

    double calculate_area() const override {
        return width * height;
    }

    double calculate_perimeter() const override {
        return 2 * (width + height);
    }
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0, "red"),
        new Rectangle(4.0, 6.0, "blue")
    };

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->calculate_area() << "\n";
        cout << "Perimeter: " << shape->calculate_perimeter() << "\n\n";
        delete shape;
    }

    return 0;
}
