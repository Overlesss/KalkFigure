#include "rectangularparallelepiped.h"
#include <typeinfo>
#include <cmath>


RectangularParallelepiped::RectangularParallelepiped(double bR, double hR, double h) : RightPrism("Rectangular Parallelepiped") {
    Rectangle* pR = new Rectangle(bR, hR); //it may throw an exception
    if(h <= 0) throw NonPositiveValues();
    createShape(pR, h);
    delete pR;
}


RectangularParallelepiped::RectangularParallelepiped(Rectangle* pR, double h) : RightPrism("Rectangular Parallelepiped") {
    if(h <= 0) throw NonPositiveValues();
    createShape(pR, h);
}


Rectangle* RectangularParallelepiped::baseShape() const {
    double base = Point2::distance(getPoints()[0], getPoints()[2]);
    double height = Point2::distance(getPoints()[0], getPoints()[4]);
    return new Rectangle(base, height);
}


void RectangularParallelepiped::expand(double n) {
    Rectangle* newBase = baseShape();
    newBase->expand(n); //it may throw an exception
    RectangularParallelepiped* pP = new RectangularParallelepiped (newBase, height() + height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


void RectangularParallelepiped::reduce(double n) {
    Rectangle* newBase = baseShape();
    newBase->reduce(n); //it may throw an exception
    RectangularParallelepiped* pP = new RectangularParallelepiped (newBase, height() - height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


RectangularParallelepiped* RectangularParallelepiped::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RectangularParallelepiped& rP = static_cast<const RectangularParallelepiped&>(s);
    Rectangle* pR = *baseShape() + *(rP.baseShape());
    return new RectangularParallelepiped(pR, height() + rP.height());
}


RectangularParallelepiped* RectangularParallelepiped::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RectangularParallelepiped& rP = static_cast<const RectangularParallelepiped&>(s);
    if(rP > *this) throw BigShape();
    double newBaseB = std::abs(baseShape()->base() - rP.baseShape()->base());
    double newBaseH = std::abs(baseShape()->height() - rP.baseShape()->height());
    double newHeight = std::abs(height() - rP.height());

    //case 1 : both heights and base shapes are congruent
   if(newBaseB == 0 && newBaseB == 0 && newHeight == 0) throw CongruentShapes();

   Rectangle* pR = nullptr;
   try { pR = new Rectangle(newBaseB, newBaseH); }
   catch(NonPositiveValues& err) {
       //case 2: congruent base shapes but different heights
       //error catched is ignored, new base shape will be equal to the current object's one
       pR = baseShape();
   }

    RectangularParallelepiped* r = new RectangularParallelepiped(pR, newHeight);
    delete pR;
    return r;
}


RectangularParallelepiped* RectangularParallelepiped::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RectangularParallelepiped& rP = static_cast<const RectangularParallelepiped&>(s);
    Rectangle* pR = *baseShape() * (*(rP.baseShape()));
    return new RectangularParallelepiped(pR, height() * (rP.height()));
}


RectangularParallelepiped* RectangularParallelepiped::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RectangularParallelepiped& rP = static_cast<const RectangularParallelepiped&>(s);

    //both operands are greater than 0
    Rectangle* pR = *baseShape() / *(rP.baseShape());
    return new RectangularParallelepiped(pR, height() / rP.height());
}
