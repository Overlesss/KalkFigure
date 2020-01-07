#include "trapezoidalprism.h"
#include <cmath>
#include <typeinfo>


TrapezoidalPrism::TrapezoidalPrism(double lbT, double sbT, double hT, double h) : RightPrism("Trapezoidal Prism") {
    IsoscelesTrapezoid* pT = new IsoscelesTrapezoid(lbT, sbT, hT); //it may throw a exceptions
    if(h <= 0) throw NonPositiveValues();
    createShape(pT, h);
    delete pT;
}


TrapezoidalPrism::TrapezoidalPrism(IsoscelesTrapezoid* pT, double h) : RightPrism("Trapezoidal Prism") {
    if(h <= 0) throw NonPositiveValues();
    createShape(pT, h);
}


IsoscelesTrapezoid* TrapezoidalPrism::baseShape() const {
    double longBase = Point2::distance(getPoints()[0], getPoints()[2]);
    double shortBase = Point2::distance(getPoints()[4], getPoints()[6]);
    double height = Point2::distance(Point2((longBase - shortBase) / 2, 0), getPoints()[4]);
    return new IsoscelesTrapezoid(longBase, shortBase, height);
}


void TrapezoidalPrism::expand(double n) {
    IsoscelesTrapezoid* newBase = baseShape();
    newBase->expand(n); //it may throw an exception
    TrapezoidalPrism* pP = new TrapezoidalPrism (newBase, height() + height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


void TrapezoidalPrism::reduce(double n) {
    IsoscelesTrapezoid* newBase = baseShape();
    newBase->reduce(n); //it may throw an exception
    TrapezoidalPrism* pP = new TrapezoidalPrism (newBase, height() - height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


TrapezoidalPrism* TrapezoidalPrism::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const TrapezoidalPrism& rP = static_cast<const TrapezoidalPrism&>(s);
    IsoscelesTrapezoid* pT = *baseShape() + *(rP.baseShape());
    return new TrapezoidalPrism(pT, height() + rP.height());
}


TrapezoidalPrism* TrapezoidalPrism::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const TrapezoidalPrism& rP = static_cast<const TrapezoidalPrism&>(s);
    if(rP > *this) throw BigShape();
    double newBaseLB = std::abs(baseShape()->longBase() - rP.baseShape()->longBase());
    double newBaseSB = std::abs(baseShape()->shortBase() - rP.baseShape()->shortBase());
    double newBaseH = std::abs(baseShape()->height() - rP.baseShape()->height());
    double newHeight = std::abs(height() - (rP.height()));

    //case 1 : both heights and base shapes are congruent
   if(newBaseLB == 0 && newBaseSB == 0 && newBaseH == 0 && newHeight == 0) throw CongruentShapes();

   IsoscelesTrapezoid* pT = nullptr;
   try { pT = new IsoscelesTrapezoid(newBaseLB, newBaseSB, newBaseH); }
   catch(NonPositiveValues& err) {
       //case 2: congruent base shapes but different heights
       //error catched is ignored, new base shape will be equal to the current object's one
       pT = baseShape();
   }

    TrapezoidalPrism* r = new TrapezoidalPrism(pT, newHeight);
    delete pT;
    return r;
}


TrapezoidalPrism* TrapezoidalPrism::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const TrapezoidalPrism& rP = static_cast<const TrapezoidalPrism&>(s);
    IsoscelesTrapezoid* pT = *baseShape() * (*(rP.baseShape()));
    return new TrapezoidalPrism(pT, height() * (rP.height()));
}


TrapezoidalPrism* TrapezoidalPrism::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const TrapezoidalPrism& rP = static_cast<const TrapezoidalPrism&>(s);

    //both operands are greater than 0
    IsoscelesTrapezoid* pT = *baseShape() / *(rP.baseShape());
    return new TrapezoidalPrism(pT, height() / rP.height());
}
