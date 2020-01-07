#include "point3.h"
#include <math.h>


Point3::Point3(double xValue, double yValue, double zValue) : Point2(xValue,yValue), z(zValue) {}


double Point3::getZ() const {
    return z;
}


double Point3::distance(const Point3& p1, const Point3& p2) {
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2) + pow(p2.z - p1.z, 2));
}


std::string Point3::toString() const {
    return "(" + Point2::toString() + "," + std::to_string(z) + ")";
}
