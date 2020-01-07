#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "regularpolygon.h"


class EquilateralTriangle : public RegularPolygon
{
private:
    void createShape(double); //function that builds an equilateral triangle starting from the length of its side

public:
    EquilateralTriangle(double =1.0); //constructor with one double type parameter, with default value, which represents the length of the side

    static double height(double); //function that returns the height of the triangle

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    EquilateralTriangle* operator+(const Plane&) const;
    EquilateralTriangle* operator-(const Plane&) const;
    EquilateralTriangle* operator*(const Plane&) const;
    EquilateralTriangle* operator/(const Plane&) const;
};

#endif // EQUILATERALTRIANGLE_H
