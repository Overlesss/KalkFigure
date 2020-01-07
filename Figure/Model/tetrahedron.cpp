#include "tetrahedron.h"
#include <math.h>
#include <typeinfo>


Tetrahedron::Tetrahedron(double e) : PlatonicSolid("Tetrahedron") {
    EquilateralTriangle* pT = new EquilateralTriangle(e); //it may throw an exception
    createShape(pT);
    delete pT;
}


Tetrahedron::Tetrahedron(EquilateralTriangle* pT) : PlatonicSolid("Tetrahedron") {
    createShape(pT);
}


void Tetrahedron::createShape(const Plane* s) {
    //creates five points representing the vertices of the tetrahedron (in the first quadrant)
    const EquilateralTriangle* pT = dynamic_cast<const EquilateralTriangle*>(s);
    if(pT) {
        const std::vector<Point2> vP = pT->getPoints();
        for(std::vector<Point2>::const_iterator it = vP.begin(); it != vP.end(); ++it) {
            setPoint(it->getX(), it->getY(), 0);
        }
        Point2* c = pT->centreOfSymmetry(); //centre of the base shape
        double h = height(pT->side()); //height of the tetrahedron
        setPoint(*c, h);
    } else throw WrongShape();
}


double Tetrahedron::height(double edge) {
    return sqrt(6) / 3 * edge;
}


double Tetrahedron::lateralSurface() const {
    return (3 * sqrt(3)) / 4 * pow(edge(), 2);
}


int Tetrahedron::schlafliSymbol_q() const { return 3; }


double Tetrahedron::inRadius() const {
    return circumRadius() / 3;
}


double Tetrahedron::circumRadius() const {
    return edge() * sqrt(6) / 4;
}


double Tetrahedron::volume() const {
    return sqrt(2) / 12 * pow(edge(), 3);
}


EquilateralTriangle* Tetrahedron::face() const {
    return new EquilateralTriangle(edge());
}


Point3* Tetrahedron::centreOfSymmetry() const {
    const std::vector<Point3> vP = this->getPoints();
    double z = 0.0;
    for(std::vector<Point3>::const_iterator it = vP.begin(); it != vP.end(); ++it) {
        z += it->getZ();
    }
    Point2* pP = face()->centreOfSymmetry();
    return new Point3(pP->getX(), pP->getY(), z / 4);
}


void Tetrahedron::expand(double n) {
    if(n < 0) throw NegativeValue();
    Tetrahedron* pT = new Tetrahedron(edge() + edge() * n / 100);
    *this = *pT;
    delete pT;
}


void Tetrahedron::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    Tetrahedron* pT = new Tetrahedron(edge() - edge() * n / 100);
    *this = *pT;
    delete pT;
}


Tetrahedron* Tetrahedron::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Tetrahedron& rT = static_cast<const Tetrahedron&>(s);
    double newEdge = edge() + rT.edge();
    return new Tetrahedron(newEdge);
}


Tetrahedron* Tetrahedron::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Tetrahedron& rT = static_cast<const Tetrahedron&>(s);
    EquilateralTriangle* pT = *face() - *(rT.face()); //it may throw exceptions
    return new Tetrahedron(pT);
}


Tetrahedron* Tetrahedron::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Tetrahedron& rT = static_cast<const Tetrahedron&>(s);
    double newEdge = edge() * rT.edge();
    return new Tetrahedron(newEdge);
}


Tetrahedron* Tetrahedron::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Tetrahedron& rT = static_cast<const Tetrahedron&>(s);

    //both operands are greater than 0
    double newEdge = edge() / rT.edge();
    return new Tetrahedron(newEdge);
}
