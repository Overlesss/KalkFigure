#ifndef CIRCLE_H
#define CIRCLE_H

#include "plane.h"


class Circle : public Plane
{
private:
    const static double PI; //Pi constant
    void createShape(double); //function that builds a circle starting from the length of its radius

public:
    Circle(double =1.0); //constructor with one double type parameter, with default value, which represents the length of the radius

    double diameter() const; //function that returns the length of the diameter
    virtual double radius() const;
    virtual double perimeter() const;
    virtual double area() const;

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    Circle* operator+(const Plane&) const;
    Circle* operator-(const Plane&) const;
    Circle* operator*(const Plane&) const;
    Circle* operator/(const Plane&) const;
};

#endif // CIRCLE_H
