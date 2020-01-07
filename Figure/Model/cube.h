#ifndef CUBE_H
#define CUBE_H

#include "platonicsolid.h"
#include "square.h"


class Cube : public PlatonicSolid
{
private:
    virtual void createShape(const Plane*); //function that builds a cube starting from its face

protected:
    virtual int schlafliSymbol_q() const;

public:
    Cube(double =1.0); //constructor with one parameter, with default value, which represent the length of the edge
    Cube(Square*); //constructor with one parameter, which represents its face; used for 2D->3D conversion

    double spaceDiagonal() const; //function that returns the length of the space diagonal, which is the segment connecting two vertices that are not on the same face
    double lateralSurface() const; //function that returns the surface of the solid, excluding the area of its base and top faces
    virtual double inRadius() const;
    virtual double circumRadius() const;
    virtual double surface() const;
    virtual double volume() const;

    virtual Square* face() const;

    virtual Point3* centreOfSymmetry() const;

    virtual void expand(double);
    virtual void reduce(double);

    Cube* operator+(const Solid&) const;
    Cube* operator-(const Solid&) const;
    Cube* operator*(const Solid&) const;
    Cube* operator/(const Solid&) const;
};

#endif // CUBE_H
