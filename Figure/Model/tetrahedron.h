#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "platonicsolid.h"
#include "equilateraltriangle.h"


class Tetrahedron : public PlatonicSolid
{
private:
    virtual void createShape(const Plane*); //function that builds a tetrahedron starting from its face

protected:
    virtual int schlafliSymbol_q() const;

public:
    Tetrahedron(double =1.0); //constructor with one parameter, with default value, which represent the length of the edge
    Tetrahedron(EquilateralTriangle*); //constructor with one parameter, which represents the face; used for 2D->3D conversion

    static double height(double); //function that returns the height of the tetrahedron
    double lateralSurface() const; //function that returns the surface of the solid, excluding the area of its base and top faces
    virtual double inRadius() const;
    virtual double circumRadius() const;
    virtual double volume() const;

    virtual EquilateralTriangle* face() const;

    virtual Point3* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    Tetrahedron* operator+(const Solid&) const;
    Tetrahedron* operator-(const Solid&) const;
    Tetrahedron* operator*(const Solid&) const;
    Tetrahedron* operator/(const Solid&) const;
};

#endif // TETRAHEDRON_H
