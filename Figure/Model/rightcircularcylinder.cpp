#include "rightcircularcylinder.h"
#include <cmath>
#include <typeinfo>


const double RightCircularCylinder::PI = atan(1) * 4;


RightCircularCylinder::RightCircularCylinder(double b, double h) : SolidOfRevolution("Right Circular Cylinder") {
    //b and h are the lenght of the base diameter and the height of the cylinder respectively

    Circle * pC = new Circle(b / 2); //it may throw an exception
    if(h <= 0) throw NonPositiveValues();
    createShape(pC, h);
    delete pC;
}


RightCircularCylinder::RightCircularCylinder(Circle* pC, double h) : SolidOfRevolution("Right Circular Cylinder") {
    if(h <= 0) throw NonPositiveValues();
    createShape(pC, h);
}


void RightCircularCylinder::createShape(const Plane* pP, double h) {
    //creates three points representing the radius of the base and the height of the cylinder (in the first quadrant)
    const Circle* pC = dynamic_cast<const Circle*>(pP);
    if(pC) {
        const std::vector<Point2> vP = pC->getPoints();
        for(std::vector<Point2>::const_iterator it = vP.begin(); it != vP.end(); ++it) {
            setPoint(it->getX(), it->getY(), 0);
        }
        Point2* c = pC->centreOfSymmetry(); //centroid of the base shape
        setPoint(*c, h);
    } else throw WrongShape();
}


Circle* RightCircularCylinder::baseShape() const {
    return new Circle(radius());
}


Rectangle* RightCircularCylinder::shapeRotated() const {
    return new Rectangle(radius(), height());
}


double RightCircularCylinder::lateralSurface() const {
    return 2 * PI * radius() * height();
}


double RightCircularCylinder::radius() const {
    return Point3::distance(getPoints()[0], getPoints()[1]);
}


double RightCircularCylinder::height() const {
    return Point3::distance(getPoints()[1], getPoints()[2]);
}


double RightCircularCylinder::surface() const {
    double baseSurface = PI * pow(radius(), 2);
    return 2 * baseSurface + lateralSurface();
}


double RightCircularCylinder::volume() const {
    return pow(radius(), 2) * PI * height();
}


Point3* RightCircularCylinder::centreOfSymmetry() const {
    Point2* pP = baseShape()->centreOfSymmetry();
    return new Point3(pP->getX(), pP->getY(), height() / 2);
}


void RightCircularCylinder::expand(double n) {
    Circle* newBase = baseShape();
    newBase->expand(n); //it may throw an exception
    RightCircularCylinder* pC = new RightCircularCylinder (newBase, height() + height() * n / 100);
    *this = *pC;
    delete newBase;
    delete pC;
}


void RightCircularCylinder::reduce(double n) {
    Circle* newBase = baseShape();
    newBase->reduce(n); //it may throw an exception
    RightCircularCylinder* pC = new RightCircularCylinder (newBase, height() - height() * n / 100);
    *this = *pC;
    delete newBase;
    delete pC;
}


RightCircularCylinder* RightCircularCylinder::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RightCircularCylinder& rC = static_cast<const RightCircularCylinder&>(s);
    Circle* pC = *baseShape() + *(rC.baseShape());
    return new RightCircularCylinder(pC, height() + rC.height());
}


RightCircularCylinder* RightCircularCylinder::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RightCircularCylinder& rC = static_cast<const RightCircularCylinder&>(s);
    if(rC > *this) throw BigShape();
    double newRadius = std::abs(radius() - rC.radius());
    double newHeight = std::abs(height() - rC.height());

    //case 1 : both heights and base shapes are congruent
   if(newRadius == 0 && newHeight == 0) throw CongruentShapes();

   Circle* pC = nullptr;
   try { pC = new Circle(newRadius); }
   catch(NonPositiveValues& err) {
       //case 2: congruent base shapes but different heights
       //error catched is ignored, new base shape will be equal to the current object's one
       pC = baseShape();
   }

    RightCircularCylinder* r = new RightCircularCylinder(pC, newHeight);
    delete pC;
    return r;
}


RightCircularCylinder* RightCircularCylinder::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RightCircularCylinder& rC = static_cast<const RightCircularCylinder&>(s);
    Circle* pC = *baseShape() * (*(rC.baseShape()));
    return new RightCircularCylinder(pC, height() * (rC.height()));
}


RightCircularCylinder* RightCircularCylinder::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const RightCircularCylinder& rC = static_cast<const RightCircularCylinder&>(s);

    //both operands are greater than 0
    Circle* pC = *baseShape() / *(rC.baseShape());
    return new RightCircularCylinder(pC, height() / rC.height());
}
