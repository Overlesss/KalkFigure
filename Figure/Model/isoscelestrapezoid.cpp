#include "isoscelestrapezoid.h"
#include <cmath>
#include <typeinfo>


IsoscelesTrapezoid::IsoscelesTrapezoid(double lB, double sB, double h) : SimplePolygon("Isosceles Trapezoid") {
    //lB, sB and h represent the lengths of the long base, short base and height respectively
    if(lB <= 0 || sB <= 0 || h <= 0) throw NonPositiveValues();
    if(lB <= sB) throw UnsuitableValues();
    createShape(lB, sB, h);
}


void IsoscelesTrapezoid::createShape(double longBase, double shortBase, double height) {
    //creates four points representing the vertices of the trapezoid (in the first quadrant)
    setPoint();
    setPoint(longBase, 0);
    setPoint((longBase - shortBase) / 2, height);
    setPoint(shortBase + (longBase - shortBase) / 2, height);
}


double IsoscelesTrapezoid::longBase() const {
    return Point2::distance(getPoints()[0], getPoints()[1]);
}


double IsoscelesTrapezoid::shortBase() const {
    return Point2::distance(getPoints()[2], getPoints()[3]);
}


double IsoscelesTrapezoid::leg() const {
    return Point2::distance(getPoints()[0], getPoints()[2]);
}


double IsoscelesTrapezoid::height() const {
    return sqrt(pow(leg(), 2) - pow((longBase() - shortBase()) / 2, 2));
}


double IsoscelesTrapezoid::diagonal() const {
    //using Pythagorean theorem
    return sqrt(longBase() * shortBase() + pow(leg(), 2));
}


double IsoscelesTrapezoid::radius() const {
    Point2 c = *(centreOfSymmetry());
    Point2 p = getPoints()[0];
    return Point2::distance(c, p);
}


double IsoscelesTrapezoid::perimeter() const {
    return longBase() + shortBase() + 2 * leg();
}


double IsoscelesTrapezoid::area() const {
    return ((longBase() + shortBase()) * height()) / 2 ;
}


Point2* IsoscelesTrapezoid::centreOfSymmetry() const {
    double x = longBase() / 2;
    double y = height() / 3 * ((2 * shortBase() + longBase()) / (shortBase() + longBase()));
    return new Point2(x, y);
}


void IsoscelesTrapezoid::expand(double n) {
    if(n < 0) throw NegativeValue();
    double newShortBase = shortBase() + shortBase() * n / 100;
    double newLongBase = longBase() + longBase() * n / 100;
    double newHeight = height() + height() * n / 100;
    IsoscelesTrapezoid* pT = new IsoscelesTrapezoid(newLongBase, newShortBase, newHeight);
    *this = *pT;
    delete pT;
}


void IsoscelesTrapezoid::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    double newShortBase = shortBase() - shortBase() * n / 100;
    double newLongBase = longBase() - longBase() * n / 100;
    double newHeight = height() - height() * n / 100;
    IsoscelesTrapezoid* pT = new IsoscelesTrapezoid(newLongBase, newShortBase, newHeight);
    *this = *pT;
    delete pT;
}


IsoscelesTrapezoid* IsoscelesTrapezoid::operator+(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const IsoscelesTrapezoid& rT = static_cast<const IsoscelesTrapezoid&>(p);
    double sumLongBase = longBase() + rT.longBase();
    double sumShortBase = shortBase() + rT.shortBase();
    double sumHeight = height() + rT.height();
    return new IsoscelesTrapezoid(sumLongBase, sumShortBase, sumHeight);
}


IsoscelesTrapezoid* IsoscelesTrapezoid::operator-(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const IsoscelesTrapezoid& rT = static_cast<const IsoscelesTrapezoid&>(p);
    if(rT > (*this)) throw BigShape();

    double longBaseDifference = std::abs(longBase() - rT.longBase());
    double shortBaseDifference = std::abs(shortBase() - rT.shortBase());
    double heightDifference = std::abs(height() - rT.height());

    //case 1 : equivalent heights and base shapes
    if((shortBaseDifference == 0 && longBaseDifference == 0 && heightDifference == 0) || area() == rT.area()) throw CongruentShapes();

    //case 2 : at least one between the height and the bases is different
    if(longBaseDifference == 0) longBaseDifference = longBase();
    if(shortBaseDifference == 0) shortBaseDifference = shortBase();
    heightDifference = (2 * (area() - rT.area())) / (longBaseDifference + shortBaseDifference);

    return new IsoscelesTrapezoid(longBaseDifference, shortBaseDifference, heightDifference);
}


IsoscelesTrapezoid* IsoscelesTrapezoid::operator*(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const IsoscelesTrapezoid& rT = static_cast<const IsoscelesTrapezoid&>(p);
    double productLongBase = longBase() * rT.longBase();
    double productShortBase = shortBase() * rT.shortBase();
    double productHeight = height() * rT.height();
    return new IsoscelesTrapezoid(productLongBase, productShortBase, productHeight);
}


IsoscelesTrapezoid* IsoscelesTrapezoid::operator/(const Plane& p) const {
    if(typeid(p) != typeid(*this)) throw DifferentShapes();
    const IsoscelesTrapezoid& rT = static_cast<const IsoscelesTrapezoid&>(p);

    //both operands are greater than 0
    double quotientLongBase = longBase() / rT.longBase();
    double quotientShortBase = shortBase() / rT.shortBase();
    double quotientHeight = height() / rT.height();
    return new IsoscelesTrapezoid(quotientLongBase, quotientShortBase, quotientHeight);
}
