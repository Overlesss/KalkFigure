#include "point2.h"
#include <math.h>


Point2::Point2(double abscissa, double ordinate) : x(abscissa), y(ordinate) {}


Point2::~Point2() {}


double Point2::getX() const {
    return x;
}


double Point2::getY() const {
    return y;
}



double Point2::distance(const Point2& p1, const Point2& p2) {
    return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}


std::string Point2::toString() const {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}
