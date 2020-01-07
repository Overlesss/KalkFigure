#include "circle.h"
#include <math.h>
#include <typeinfo>


const double Circle::PI = atan(1) * 4;


Circle::Circle(double r) : Plane("Circle") {
    //r represents the length of the radius
    if(r <= 0) throw NonPositiveValues();
    createShape(r);
}


void Circle::createShape(double radius) {
    //creates two points representing the radius of the circle by calculating the segment's end points (in the first quadrant)
    setPoint(radius, 0);
    setPoint(radius, radius);
}


double Circle::diameter() const {
    return 2 * radius();
}


double Circle::radius() const {
    return Point2::distance(getPoints()[0], getPoints()[1]);
}


double Circle::perimeter() const {
    return 2 * radius() * PI;
}


double Circle::area() const {
    return PI * pow(radius(), 2);
}


Point2* Circle::centreOfSymmetry() const {
    return new Point2(radius(), radius());
}


void Circle::expand(double n) {
    if(n < 0) throw NegativeValue();
    Circle* c = new Circle(radius() + radius() * n / 100);
    *this = *c;
    delete c;
}


void Circle::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    Circle* c = new Circle(radius() - radius() * n / 100);
    *this = *c;
    delete c;
}


Circle* Circle::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Circle& rC = static_cast<const Circle&>(p);
    double sum = radius() + rC.radius();
    return new Circle(sum);
}


Circle* Circle::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Circle& rC = static_cast<const Circle&>(p);
    if(rC > (*this)) throw BigShape();
    double difference = radius() - rC.radius();
    if(difference == 0) throw CongruentShapes();
    return new Circle(difference);
}


Circle* Circle::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Circle& rC = static_cast<const Circle&>(p);
    double product = radius() * rC.radius();
    return new Circle(product);
}


Circle* Circle::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Circle& rC = static_cast<const Circle&>(p);

    //both operands are greater than 0
    double quotient = radius() / rC.radius();
    return new Circle(quotient);
}
