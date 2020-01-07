#ifndef ISOSCELESTRAPEZOID_H
#define ISOSCELESTRAPEZOID_H

#include "simplepolygon.h"


class IsoscelesTrapezoid : public SimplePolygon
{
private:
    void createShape(double, double, double); //function that builds an isosceles trapezoid starting from the length of its two bases and height

public:
    IsoscelesTrapezoid(double =2.0, double =1.0, double =1.0); //constructor with three double type parameters, with default values, which represent the length of its two bases and height

    double longBase() const; //function that returns the length of the long base
    double shortBase() const; //function that returns the length of the short base
    double leg() const; //function that returns the length of the leg
    double height() const; //function that returns the height of the trapezoid
    double diagonal() const; //function that returns the length of the diagonal
    virtual double radius() const;
    virtual double perimeter() const;
    virtual double area() const;

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    IsoscelesTrapezoid* operator+(const Plane&) const;
    IsoscelesTrapezoid* operator-(const Plane&) const;
    IsoscelesTrapezoid* operator*(const Plane&) const;
    IsoscelesTrapezoid* operator/(const Plane&) const;
};

#endif // ISOSCELESTRAPEZOID_H
