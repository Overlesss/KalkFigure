#include "cube.h"
#include <math.h>
#include <typeinfo>


Cube::Cube(double e) : PlatonicSolid("Cube") {
    Square* pS = new Square(e); //it may throw an exception
    createShape(pS);
    delete pS;
}


Cube::Cube(Square* pS) : PlatonicSolid("Cube") {
    createShape(pS);
}


void Cube::createShape(const Plane* p) {
    //creates eight points representing the vertices of the cube (in the first quadrant)
    const Square* pS = dynamic_cast<const Square*>(p);
    if(pS) {
        double h = pS->side();
        const std::vector<Point2> vP = pS->getPoints();
        for(std::vector<Point2>::const_iterator it = vP.begin(); it != vP.end(); ++it) {
            setPoint(it->getX(), it->getY(), 0);
            setPoint(it->getX(), it->getY(), h);
        }
    } else throw WrongShape();
}


double Cube::spaceDiagonal() const{
    return edge() * sqrt(3);
}


double Cube::lateralSurface() const {
    return 4 * pow(edge(), 2);
}


int Cube::schlafliSymbol_q() const { return 3; }


double Cube::inRadius() const {
    return edge() / 2;
}


double Cube::circumRadius() const {
    return edge() * sqrt(3) / 2;
}


double Cube::surface() const {
    return 6 * pow(edge(), 2);
}


double Cube::volume() const {
    return pow(edge(), 3);
}


Square* Cube::face() const {
    return new Square(edge());
}


Point3* Cube::centreOfSymmetry() const {
    Point2* pP = face()->centreOfSymmetry();
    return new Point3(pP->getX(), pP->getY(), edge() / 2);
}


void Cube::expand(double n) {
    if(n < 0) throw NegativeValue();
    Cube* pC = new Cube(edge() + edge() * n / 100);
    *this = *pC;
    delete pC;
}


void Cube::reduce(double n) {
    if(n < 0 || n >= 100) throw ValueOutOfRange();
    Cube* pC = new Cube(edge() - edge() * n / 100);
    *this = *pC;
    delete pC;
}


Cube* Cube::operator+(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Cube& rC = static_cast<const Cube&>(s);
    double newEdge = edge() + rC.edge();
    return new Cube(newEdge);
}


Cube* Cube::operator-(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Cube& rC = static_cast<const Cube&>(s);
    Square* pS = *face() - *(rC.face()); //it may throw exceptions
    return new Cube(pS);
}


Cube* Cube::operator*(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Cube& rC = static_cast<const Cube&>(s);
    double newEdge = edge() * rC.edge();
    return new Cube(newEdge);
}


Cube* Cube::operator/(const Solid& s) const {
    if(typeid(s) != typeid(*this)) throw DifferentShapes();
    const Cube& rC = static_cast<const Cube&>(s);

    //both operands are greater than 0
    double newEdge = edge() / rC.edge();
    return new Cube(newEdge);
}
