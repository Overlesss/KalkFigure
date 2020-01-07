#ifndef SIMPLEPOLYGON_H
#define SIMPLEPOLYGON_H

#include "plane.h"


//Class that represents a simple polygon, which is a flat shape consisting of straight, non-intersecting sides that are joined pair-wise to form a closed path
class SimplePolygon : public Plane
{
public:
    SimplePolygon(std::string ="");

    int vertexCount() const; //function that returns the number of vertices

    //general formulas, may be implemented more efficiently in concrete classes
    virtual Point2* centreOfSymmetry() const;
    virtual double perimeter() const;
    virtual double area() const;
};

#endif // SIMPLEPOLYGON_H
