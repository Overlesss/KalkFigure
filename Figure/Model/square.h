#ifndef SQUARE_H
#define SQUARE_H

#include "regularpolygon.h"


class Square : public RegularPolygon
{
private:
    void createShape(double); //function that builds a square starting from the length of its side

public:
    Square(double =1.0); //constructor with one double type parameter, with default value, which represents the length of the side

    double diagonal() const; //function that returns the length of the diagonal

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    Square* operator+(const Plane&) const;
    Square* operator-(const Plane&) const;
    Square* operator*(const Plane&) const;
    Square* operator/(const Plane&) const;
};

#endif // SQUARE_H
