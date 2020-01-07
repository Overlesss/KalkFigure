#include "rightprism.h"


RightPrism::RightPrism(std::string n) : Polyhedron(n) {}


void RightPrism::createShape(const Plane *pP, double h) {
    //creates 2n points representing the vertices of the polyhedron with n-sided polygonal base
    //pP has to be a polygon
    const SimplePolygon* pSP = dynamic_cast<const SimplePolygon*>(pP);
    if(pSP) {
        const std::vector<Point2> vP = pP->getPoints();
        for(std::vector<Point2>::const_iterator it = vP.begin(); it != vP.end(); ++it) {
            setPoint(it->getX(), it->getY(), 0);
            setPoint(it->getX(), it->getY(), h);
        }
    } else throw WrongShape();
}


double RightPrism::height() const {
    return Point3::distance(getPoints()[0], getPoints()[1]);
}


double RightPrism::lateralSurface() const {
    return baseShape()->perimeter() * height();
}


int RightPrism::faceCount() const {
    return baseShape()->vertexCount() + 2;
}


int RightPrism::edgeCount() const {
    return baseShape()->vertexCount() * 3;
}


double RightPrism::surface() const {
    return baseShape()->area() * 2 + lateralSurface();
}


double RightPrism::volume() const {
    return baseShape()->area() * height();
}


Point3* RightPrism::centreOfSymmetry() const {
    Point2* pP = baseShape()->centreOfSymmetry();
    return new Point3(pP->getX(), pP->getY(), height() / 2);
}
