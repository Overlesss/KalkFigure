#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "simplepolygon.h"


class Rectangle : public SimplePolygon
{
private:
    void createShape(double, double); //function that builds a rectangle starting from the length of its base and height

public:
    Rectangle(double =2.0, double =1.0); //constructor with two double type parameters, both with default values, which represent the length of the base and the height

    double base() const; //function that returns the length of the base
    double height() const; //function that returns the height of the rectangle
    double diagonal() const; //function that returns the length of the diagonal
    virtual double radius() const;
    virtual double perimeter() const;
    virtual double area() const;

    virtual Point2* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    Rectangle* operator+(const Plane&) const;
    Rectangle* operator-(const Plane&) const;
    Rectangle* operator*(const Plane&) const;
    Rectangle* operator/(const Plane&) const;
};

#endif // RECTANGLE_H
