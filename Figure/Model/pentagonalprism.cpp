#include "pentagonalprism.h"
#include <cmath>
#include <typeinfo>


PentagonalPrism::PentagonalPrism(double e, double h) : RightPrism("Pentagonal Prism") {
    RegularPentagon* pP = new RegularPentagon(e); //it may throw an exception
    if(h <= 0) throw NonPositiveValues();
    createShape(pP, h);
    delete pP;
}


PentagonalPrism::PentagonalPrism(RegularPentagon* pR, double h) : RightPrism("Pentagonal Prism") {
    if(h <= 0) throw NonPositiveValues();
    createShape(pR, h);
}


RegularPentagon* PentagonalPrism::baseShape() const {
    return new RegularPentagon(Point2::distance(getPoints()[0], getPoints()[2]));
}


void PentagonalPrism::expand(double n) {
    RegularPentagon* newBase = baseShape();
    newBase->expand(n);
    PentagonalPrism* pP = new PentagonalPrism (newBase, height() + height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


void PentagonalPrism::reduce(double n) {
    RegularPentagon* newBase = baseShape();
    newBase->reduce(n);
    PentagonalPrism* pP = new PentagonalPrism (newBase, height() - height() * n / 100);
    *this = *pP;
    delete newBase;
    delete pP;
}


PentagonalPrism* PentagonalPrism::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const PentagonalPrism& rP = static_cast<const PentagonalPrism&>(s);
    RegularPentagon* pP = *baseShape() + *(rP.baseShape());
    return new PentagonalPrism(pP, height() + rP.height());
}


PentagonalPrism* PentagonalPrism::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const PentagonalPrism& rP = static_cast<const PentagonalPrism&>(s);
    if(rP > *this) throw BigShape();
    double newEdge = std::abs(baseShape()->side() - rP.baseShape()->side());
    double newHeight = std::abs(height() - rP.height());

    //case 1 : both heights and base shapes are congruent
   if(newEdge == 0 && newHeight == 0) throw CongruentShapes();

   RegularPentagon* pP = nullptr;
   try { pP = new RegularPentagon(newEdge); }
   catch(NonPositiveValues& err) {
       //case 2: congruent base shapes but different heights
       //error catched is ignored, new base shape will be equal to the current object's one
       pP = baseShape();
   }

   PentagonalPrism* r = new PentagonalPrism(pP, newHeight);
   delete pP;
   return r;
}


PentagonalPrism* PentagonalPrism::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const PentagonalPrism& rP = static_cast<const PentagonalPrism&>(s);
    RegularPentagon* pP = *baseShape() * (*(rP.baseShape()));
    return new PentagonalPrism(pP, height() * (rP.height()));
}


PentagonalPrism* PentagonalPrism::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const PentagonalPrism& rP = static_cast<const PentagonalPrism&>(s);

    //both operands are greater than 0
    RegularPentagon* pP = *baseShape() / *(rP.baseShape());
    return new PentagonalPrism(pP, height() / rP.height());
}
