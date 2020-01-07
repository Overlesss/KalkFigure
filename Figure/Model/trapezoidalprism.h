#ifndef TRAPEZOIDALPRISM_H
#define TRAPEZOIDALPRISM_H

#include "rightprism.h"
#include "isoscelestrapezoid.h"


class TrapezoidalPrism : public RightPrism
{
public:
    TrapezoidalPrism(double =2.0, double =1.0, double =1.0, double =1.0); //constructor with four double type parameters, both with default values, which represent the length of the bases and heigth of the base shape, and the height of the solid
    TrapezoidalPrism(IsoscelesTrapezoid*, double =1.0); //constructor with two parameters, the first one represents the base shape and the second one, with default value, represents the height of the solid; used for 2D->3D conversion

    virtual IsoscelesTrapezoid* baseShape() const;

    virtual void expand(double);
    virtual void reduce(double);

    TrapezoidalPrism* operator+(const Solid&) const;
    TrapezoidalPrism* operator-(const Solid&) const;
    TrapezoidalPrism* operator*(const Solid&) const;
    TrapezoidalPrism* operator/(const Solid&) const;
};

#endif // TRAPEZOIDALPRISM_H
