#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "simplepolygon.h"


//Class that represents a convex regular polygon, which is equiangular and equilateral
class RegularPolygon : public SimplePolygon
{
private:
    const static double PI; //Pi constant

public:
    RegularPolygon(std::string = "");

    virtual double side() const; //function that returns the length of the side
    double apothem() const; //function that returns the length of the line segment from the centroid to the midpoint of one of the sides
    virtual double radius() const;
    virtual double perimeter() const;
    virtual double area() const;
};

#endif // REGULARPOLYGON_H
