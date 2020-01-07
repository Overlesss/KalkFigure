#include "equilateraltriangle.h"
#include <math.h>
#include <typeinfo>


EquilateralTriangle::EquilateralTriangle(double s) : RegularPolygon("Equilateral Triangle") {
    //s represents the length of the side
    if(s <= 0) throw NonPositiveValues();
    createShape(s);
}


void EquilateralTriangle::createShape(double side) {
    //creates three points representing the vertices of the triangle (in the first quadrant)
    setPoint();
    setPoint(side, 0);
    setPoint(side / 2, height(side));
}


double EquilateralTriangle::height(double side) {
    return (side * sqrt(3)) / 2;
}


Point2* EquilateralTriangle::centreOfSymmetry() const {
    return new Point2(side() / 2, apothem());
}


void EquilateralTriangle::expand(double n) {
    if(n < 0) throw NegativeValue();
    EquilateralTriangle* pT = new EquilateralTriangle(side() + side() * n / 100);
    *this = *pT;
    delete pT;
}


void EquilateralTriangle::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    EquilateralTriangle* pT = new EquilateralTriangle(side() - side() * n / 100);
    *this = *pT;
    delete pT;
}


EquilateralTriangle* EquilateralTriangle::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const EquilateralTriangle& rT = static_cast<const EquilateralTriangle&>(p);
    double sum = side() + rT.side();
    return new EquilateralTriangle(sum);
}


EquilateralTriangle* EquilateralTriangle::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const EquilateralTriangle& rT = static_cast<const EquilateralTriangle&>(p);
    if(rT > (*this)) throw BigShape();
    double difference = side() - rT.side();
    if(difference == 0) throw CongruentShapes();
    return new EquilateralTriangle(difference);
}


EquilateralTriangle* EquilateralTriangle::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const EquilateralTriangle& rT = static_cast<const EquilateralTriangle&>(p);
    double product = side() * rT.side();
    return new EquilateralTriangle(product);
}


EquilateralTriangle* EquilateralTriangle::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const EquilateralTriangle& rT = static_cast<const EquilateralTriangle&>(p);

    //both operands are greater than 0
    double quotient = side() / rT.side();
    return new EquilateralTriangle(quotient);
}
