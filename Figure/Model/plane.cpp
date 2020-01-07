#include "plane.h"
#include <typeinfo>


Plane::Plane(std::string n) : Shape(n) {}


void Plane::setPoint(double a, double o) {
    points.push_back(Point2(a,o));
}


const std::vector<Point2>& Plane::getPoints() const {
    return points;
}


Plane& Plane::operator=(const Plane& p) {
    if(getName() != p.getName())
        setName(p.getName());
    points = p.points; //assigns new contents, replacing current contents of points and modifying its size accordingly.
    return *this;
}


bool Plane::operator>(const Plane& p) const {
    return area() > p.area();
}
