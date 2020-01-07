#ifndef RECTANGULARPARALLELEPIPED_H
#define RECTANGULARPARALLELEPIPED_H

#include "rightprism.h"
#include "rectangle.h"


class RectangularParallelepiped : public RightPrism
{
public:
    RectangularParallelepiped(double =2.0, double =1.0, double =1.0); //constructor with three double type parameters, with default values, which represent the length of the base and heigth of the base, and the height of the solid
    RectangularParallelepiped(Rectangle*, double =1.0); //constructor with two parameters, the first one represents the base shape and the second one, with default value, represents the height of the solid; used for 2D->3D conversion

    virtual Rectangle* baseShape() const;

    virtual void expand(double);
    virtual void reduce(double);

    RectangularParallelepiped* operator+(const Solid&) const;
    RectangularParallelepiped* operator-(const Solid&) const;
    RectangularParallelepiped* operator*(const Solid&) const;
    RectangularParallelepiped* operator/(const Solid&) const;
};

#endif // RECTANGULARPARALLELEPIPED_H
