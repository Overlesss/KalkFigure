#ifndef SOLID_H
#define SOLID_H

#include "shape.h"
#include "point3.h"
#include <vector>


//Class that represents a 3-dimensional shape
class Solid : public Shape
{
private:
    std::vector<Point3> points; //the Cartesian coordinates of the points on the space that represent a 3-dimensional shape

protected:
    void setPoint(double =0, double =0, double =0); //function that assigns values to points
    void setPoint(const Point2&, double =0); //function that assigns values to points, starting from a 2-dimensional point

public:
    Solid(std::string = "");    

    const std::vector<Point3>& getPoints() const; //function that returns the points of a 3-dimensional shape

    virtual double surface() const =0; //function that returns the total area that the surface of the solid shape occupies
    virtual double volume() const =0; //function that returns the quantity of 3-dimensional space enclosed by a closed surface

    virtual Solid& operator=(const Solid&); //function that assigns new name and points values to the current object, if different from the previous ones
    virtual bool operator>(const Solid&) const; //function that compares two solid shapes based on their volume
    virtual double lateralSurface() const =0;

    virtual Solid* operator+(const Solid&) const =0; //function that returns the sum of two solid shapes of the same type
    virtual Solid* operator-(const Solid&) const =0; //function that returns the difference of two solid shapes of the same type
    virtual Solid* operator*(const Solid&) const =0; //function that returns the product of two solid shapes of the same type
    virtual Solid* operator/(const Solid&) const =0; //function that returns the quotient of two solid shapes of the same type
};

#endif // SOLID_H
