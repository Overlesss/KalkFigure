#ifndef SOLIDOFREVOLUTION_H
#define SOLIDOFREVOLUTION_H

#include "solid.h"
#include "plane.h"


//Class that represents a solid shape obtained by rotating a plane shape around a straight line (the axis of revolution) which lies on the same plane
class SolidOfRevolution : public Solid
{
public:
    SolidOfRevolution(std::string = "");

    virtual Plane* shapeRotated() const =0; //function that returns the rotated plane shape
    virtual double height() const =0; //function that returns the height of the solid
};

#endif // SOLIDOFREVOLUTION_H
