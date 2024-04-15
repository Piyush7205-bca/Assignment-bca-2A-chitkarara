#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
private:
    double circleRadius;

public:
    Circle(double r) : circleRadius(r) {}

    double calculateArea() const override {
        return M_PI * circleRadius * circleRadius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * circleRadius;
    }
};

class Rectangle : public Shape {
private:
    double rectLength;
    double rectWidth;

public:
    Rectangle(double l, double w) : rectLength(l), rectWidth(w) {}

    double calculateArea() const override {
        return rectLength * rectWidth;
    }

    double calculatePerimeter() const override {
        return 2 * (rectLength + rectWidth);
    }
};

class Triangle : public Shape {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

    double calculateArea() const override {
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }
};

int main() {
    Circle myCircle(5);
    Rectangle myRectangle(4, 6);
    Triangle myTriangle(3, 4, 5);

    std::cout << "Circle area: " << myCircle.calculateArea() << std::endl;
    std::cout << "Circle perimeter: " << myCircle.calculatePerimeter() << std::endl;

    std::cout << "Rectangle area: " << myRectangle.calculateArea() << std::endl;
    std::cout << "Rectangle perimeter: " << myRectangle.calculatePerimeter() << std::endl;

    std::cout << "Triangle area: " << myTriangle.calculateArea() << std::endl;
    std::cout << "Triangle perimeter: " << myTriangle.calculatePerimeter() << std::endl;

    return 0;
}

