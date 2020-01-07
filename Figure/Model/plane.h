#ifndef PLANE_H
#define PLANE_H

#include "shape.h"
#include "point2.h"
#include <vector>


//Class that represents a 2-dimensional shape
class Plane : public Shape
{
private:
    std::vector<Point2> points; //the Cartesian coordinates of the points on the plane that represent a 2-dimensional shape

protected:
    void setPoint(double =0, double =0); //function that assigns values to points

public:
    Plane(std::string ="");

    const std::vector<Point2>& getPoints() const; //function that returns the points of a 2-dimensional shape

    virtual double radius() const =0; //if TD(*this) <= SimplePolygon, the radius is the length of the circumcircle of the polygon
    virtual double perimeter() const =0; //function that returns the path that surrounds a 2-dimensional shape
    virtual double area() const =0; //function that returns the extent of a 2-dimensional shape on the plane

    virtual Plane& operator=(const Plane&); //function that assigns new name and points values to the current object, if different from the previous ones
    virtual bool operator>(const Plane&) const; //function that compares two plane shapes based on their area

    virtual Plane* operator+(const Plane&) const =0; //function that returns the sum of two plane shapes of the same type
    virtual Plane* operator-(const Plane&) const =0; //function that returns the difference of two plane shapes of the same type
    virtual Plane* operator*(const Plane&) const =0; //function that returns the product of two plane shapes of the same type
    virtual Plane* operator/(const Plane&) const =0; //function that returns the quotient of two plane shapes of the same type
};

#endif // PLANE_H
