#ifndef POINT3_H
#define POINT3_H

#include "point2.h"


//Class that represents an ordered triplet (x, y, z) in the three-dimensional Euclidean space, with the additional third double type number representing depth (z)
class Point3 : public Point2
{
private:
    double z;
public:
    Point3(double =0, double =0, double =0); //constructor with three double type parameters, with default values, which represent the x, y and z values respectively

    double getZ() const; //function that returns the z value of a point
    static double distance(const Point3&, const Point3&); //function that returns the distance between two points
    virtual std::string toString() const;
};

#endif // POINT3_H
