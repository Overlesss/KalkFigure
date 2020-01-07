#ifndef PENTAGONALPRISM_H
#define PENTAGONALPRISM_H

#include "rightprism.h"
#include "regularpentagon.h"


class PentagonalPrism : public RightPrism
{
public:
    PentagonalPrism(double =1.0, double =1.0); //constructor with two double type parameters, both with default values, which represent the length of the base's side and the height of the solid
    PentagonalPrism(RegularPentagon*, double =1.0); //constructor with two parameters, the first one represents the base shape and the second one, with default value, represents the height of the solid; used for 2D->3D conversion

    virtual RegularPentagon* baseShape() const;

    virtual void expand(double);
    virtual void reduce(double);

    PentagonalPrism* operator+(const Solid&) const;
    PentagonalPrism* operator-(const Solid&) const;
    PentagonalPrism* operator*(const Solid&) const;
    PentagonalPrism* operator/(const Solid&) const;
};

#endif // PENTAGONALPRISM_H
