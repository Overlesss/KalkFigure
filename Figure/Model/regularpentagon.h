#ifndef REGULARPENTAGON_H
#define REGULATPENTAGON_H

#include "regularpolygon.h"


class RegularPentagon : public RegularPolygon
{
private:
    void createShape(double); //function that builds a regular pentagon starting from the length of its side

public:
    RegularPentagon(double =1); //constructor with one double type parameter, with default value, which represents the length of the side

    static double height(double); //function that returns the height of the pentagon
    static double diagonal(double); //function that returns the length of the diagonal

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    RegularPentagon* operator+(const Plane&) const;
    RegularPentagon* operator-(const Plane&) const;
    RegularPentagon* operator*(const Plane&) const;
    RegularPentagon* operator/(const Plane&) const;
};

#endif // REGULARPENTAGON_H
