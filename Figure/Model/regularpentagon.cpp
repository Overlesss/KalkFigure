#include "regularpentagon.h"
#include <math.h>
#include <typeinfo>


RegularPentagon::RegularPentagon(double s) : RegularPolygon("Regular Pentagon") {
    //s represents side length
    if(s <= 0) throw NonPositiveValues();
    createShape(s);
}


void RegularPentagon::createShape(double side) {
    //creates five points representing the vertices of the pentagon (in the first quadrant)
    double auxb = (diagonal(side) - side) / 2;
    setPoint(auxb, 0);
    setPoint(auxb + side, 0);

    //using Pythagorean theorem on the a right triangle built using auxb as a base and l as the hypotenuse, auxh will be the height
    double auxh = sqrt(pow(side, 2) - pow(auxb, 2));
    setPoint(0, auxh);
    setPoint(diagonal(side), auxh);

    setPoint(side / 2 + auxb, height(side));
}


double RegularPentagon::height(double side) {
    return side * sqrt(5 + 2 * sqrt(5)) / 2;
    //return apothem() + radius();
}


double RegularPentagon::diagonal(double side) {
    return (side * (1.0 + sqrt(5))) / 2;
}


Point2* RegularPentagon::centreOfSymmetry() const {
    //a regular pentagon can be broken down into 5 identical isosceles triangles:
    //the base of each triangle represents the side of the pentagon,
    //the legs of each triangle represent the radii of the pentagon,
    //the height of each triangle represents the apothem of the pentagon
    double x = diagonal(side()) / 2;
    double y = apothem();
    return new Point2(x,y);
}


void RegularPentagon::expand(double n) {
    if(n < 0) throw NegativeValue();
    RegularPentagon* pP = new RegularPentagon(side() + side() * n / 100);
    *this = *pP;
    delete pP;
}


void RegularPentagon::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    RegularPentagon* pP = new RegularPentagon(side() - side() * n / 100);
    *this = *pP;
    delete pP;
}


RegularPentagon* RegularPentagon::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const RegularPentagon& rP = static_cast<const RegularPentagon&>(p);
    double sum = side() + rP.side();
    return new RegularPentagon(sum);
}


RegularPentagon* RegularPentagon::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const RegularPentagon& rP = static_cast<const RegularPentagon&>(p);
    if(rP > (*this)) throw BigShape();
    double difference = side() - rP.side();
    if(difference == 0) throw CongruentShapes();
    return new RegularPentagon(difference);
}


RegularPentagon* RegularPentagon::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const RegularPentagon& rP = static_cast<const RegularPentagon&>(p);
    double product = side() * rP.side();
    return new RegularPentagon(product);
}


RegularPentagon* RegularPentagon::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const RegularPentagon& rP = static_cast<const RegularPentagon&>(p);

    //both operands are greater than 0
    double quotient = side() / rP.side();
    return new RegularPentagon(quotient);
}
