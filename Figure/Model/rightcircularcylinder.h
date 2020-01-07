#ifndef RIGHTCIRCULARCYLINDER_H
#define RIGHTCIRCULARCYLINDER_H

#include "solidofrevolution.h"
#include "rectangle.h"
#include "circle.h"


class RightCircularCylinder : public SolidOfRevolution
{
private:
    const static double PI; //Pi constant
    void createShape(const Plane* p, double); //function that builds a cylinder starting from its base shape and the length of its height

public:
    RightCircularCylinder(double =1.0, double =1.0); //constructor with two double type parameters, both with default values, which represent the length of the base and the height
    RightCircularCylinder(Circle*, double =1.0); //constructor with two parameters, the first one represents the base shape and the second one, with default value, represents the height of the solid; used for 2D->3D conversion

    Circle* baseShape() const; //function that returns the base (and top) plane shape; used for 3D->2D conversion
    virtual Rectangle* shapeRotated() const;

    double lateralSurface() const; //function that returns the surface of the solid, excluding the area of its base and top faces
    double radius() const;
    virtual double height() const;
    virtual double surface() const;
    virtual double volume() const;

    virtual Point3* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    RightCircularCylinder* operator+(const Solid&) const;
    RightCircularCylinder* operator-(const Solid&) const;
    RightCircularCylinder* operator*(const Solid&) const;
    RightCircularCylinder* operator/(const Solid&) const;
};

#endif // RIGHTCIRCULARCYLINDER_H
