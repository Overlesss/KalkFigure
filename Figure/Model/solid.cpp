#include "solid.h"


Solid::Solid(std::string n) : Shape(n) {}


void Solid::setPoint(double p1, double p2, double p3) {
    points.push_back(Point3(p1, p2, p3));
}


void Solid::setPoint(const Point2& p, double d) {
    points.push_back(Point3(p.getX(), p.getY(), d));
}


const std::vector<Point3>& Solid::getPoints() const {
    return points;
}


Solid& Solid::operator=(const Solid& p) {
    if(getName() != p.getName())
        setName(p.getName());
    points = p.points; //the assignment replaces current content of points, and modifies its size accordingly.
    return *this;
}


bool Solid::operator>(const Solid& p) const {
    return volume() > p.volume();
}
