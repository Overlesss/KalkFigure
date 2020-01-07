#ifndef SHAPE_H
#define SHAPE_H

#include "point2.h"
#include <string>
#include "Eccezioni/kalkexception.h"


//Class that represents a shape on the Cartesian coordinate system, and implements its geometric functions
class Shape
{
private:
    std::string name; //the name of the shape

public:
    Shape(std::string = "");
    virtual ~Shape(); //virtual destructor

    std::string getName() const; //function that returns the name of the shape
    void setName(std::string); //function that assigns the name to the shape

    virtual Point2* centreOfSymmetry() const =0; //function that returns the Cartesian coordinates of the centroid for plane shapes, and centre of mass for solid shapes

    virtual void expand(double) =0; //function that expands the boundaries of the shape by a percentage value
    virtual void reduce(double) =0; //function that reduces the boundaries of the shape by a percentage value
};

#endif // SHAPE_H
