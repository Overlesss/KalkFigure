#include "square.h"
#include <math.h>
#include <typeinfo>


Square::Square(double s) : RegularPolygon("Square") {
    //s represents the length of the side
    if(s <= 0) throw NonPositiveValues();
    createShape(s);
}


void Square::createShape(double side) {
    //creates four points representing the vertices of the square (in the first quadrant)
    setPoint();
    setPoint(0, side);
    setPoint(side, 0);
    setPoint(side, side);
}


double Square::diagonal() const {
    return sqrt(2) * side();
}


Point2* Square::centreOfSymmetry() const {
    return new Point2(side() / 2, side() / 2);
}


void Square::expand(double n) {
    if(n < 0) throw NegativeValue();
    Square* pS = new Square(side() + side() * n / 100);
    *this = *pS;
    delete pS;
}


void Square::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    Square* pS = new Square(side() - side() * n / 100);
    *this = *pS;
    delete pS;
}


Square* Square::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Square& rS = static_cast<const Square&>(p);
    double sum = side() + rS.side();
    return new Square(sum);
}


Square* Square::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Square& rS = static_cast<const Square&>(p);
    if(rS > (*this)) throw BigShape();
    double difference = side() - rS.side();
    if(difference == 0) throw CongruentShapes();
    return new Square(difference);
}


Square* Square::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Square& rS = static_cast<const Square&>(p);
    double product = side() * rS.side();
    return new Square(product);
}


Square* Square::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Square& rS = static_cast<const Square&>(p);

    //both operands are greater than 0
    double quotient = side() / rS.side();
    return new Square(quotient);
}
