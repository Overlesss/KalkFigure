#include "rectangle.h"
#include <cmath>
#include <typeinfo>


Rectangle::Rectangle(double b, double h) : SimplePolygon("Rectangle") {
    //b and h represent the length of the base and height respectively
    if(b <= 0 || h <= 0) throw NonPositiveValues();
    createShape(b, h);
}


void Rectangle::createShape(double base, double height) {
    //creates four points representing the vertices of the square (in the first quadrant)
    setPoint();
    setPoint(base,0);
    setPoint(0,height);
    setPoint(base,height);
}


double Rectangle::base() const {
    return Point2::distance(getPoints()[0], getPoints()[1]);
}


double Rectangle::height() const {
    return Point2::distance(getPoints()[0], getPoints()[2]);
}


double Rectangle::diagonal() const {
    return sqrt(pow(base(), 2) + pow(height(), 2));
}


double Rectangle::radius() const {
    Point2 c = *(centreOfSymmetry());
    Point2 p = getPoints()[0];
    return Point2::distance(c, p);
}


double Rectangle::perimeter() const {
    return base() * 2 + height() * 2;
}


double Rectangle::area() const {
    return base() * height();
}


Point2* Rectangle::centreOfSymmetry() const {
    return new Point2(base() / 2, height() / 2);
}


void Rectangle::expand(double n) {
    if(n < 0) throw NegativeValue();
    double newBase = base() + base() * n / 100;
    double newHeight = height() + height() * n / 100;
    Rectangle* pR = new Rectangle(newBase, newHeight);
    *this = *pR;
    delete pR;
}


void Rectangle::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    double newBase = base() - base() * n / 100;
    double newHeight = height() - height() * n / 100;
    Rectangle *pR = new Rectangle(newBase, newHeight);
    *this = *pR;
    delete pR;
}


Rectangle* Rectangle::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Rectangle& rR = static_cast<const Rectangle&>(p);
    double sumBase = base() + rR.base();
    double sumHeight = height() + rR.height();
    return new Rectangle(sumBase, sumHeight);
}


Rectangle* Rectangle::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Rectangle& r = static_cast<const Rectangle&>(p);
    if(r > (*this)) throw BigShape();

    double baseDifference = std::abs(base() - r.base());
    double heightDifference = std::abs(height() - r.height());

    //case 1 : the two shapes are congruent
    if(baseDifference == 0 && heightDifference == 0) throw CongruentShapes();

    //case 2 : one between base/height of the current object is equal to the one of r
    if(baseDifference == 0) baseDifference = base();
        else if(heightDifference == 0) heightDifference = height();

    return new Rectangle(baseDifference, heightDifference);
}


Rectangle* Rectangle::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Rectangle& rR = static_cast<const Rectangle&>(p);
    double productBase = height() * rR.height();
    double productHeight = height() * rR.height();
    return new Rectangle(productBase, productHeight);
}


Rectangle* Rectangle::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const Rectangle& rR = static_cast<const Rectangle&>(p);

    //both operands are greater than 0
    double quotientBase = base() / rR.base();
    double quotientHeight = height() / rR.height();
    return new Rectangle(quotientBase, quotientHeight);
}
