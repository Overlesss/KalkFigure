#include "regularpolygon.h"
#include <math.h>


const double RegularPolygon::PI = atan(1) * 4;


RegularPolygon::RegularPolygon(std::string n) : SimplePolygon(n) {}


double RegularPolygon::side() const {
    return Point2::distance(getPoints()[0], getPoints()[1]);
}


double RegularPolygon::apothem() const {
    return side() / (2 * tan(PI / vertexCount()));
}


double RegularPolygon::radius() const {
    Point2 c = *(centreOfSymmetry());
    Point2 p = getPoints()[0];
    return Point2::distance(c, p);
}


double RegularPolygon::perimeter() const {
    return side() * vertexCount();
}


double RegularPolygon::area() const {
    return (apothem() * perimeter()) / 2;
}
