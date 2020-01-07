#ifndef RIGHTPRISM_H
#define RIGHTPRISM_H

#include "polyhedron.h"
#include "simplepolygon.h"


//Class that represents a polyhedron comprising an n-sided polygonal base, a second base which is a translated copy (rigidly moved without rotation) of the first, and n other faces (necessarily all parallelograms) joining corresponding sides of the two bases; the joining edges and faces are perpendicular to the base faces
class RightPrism : public Polyhedron
{
protected:
    void createShape(const Plane*, double); //function that builds a right prism starting from its base plane shape and its height

public:
    RightPrism(std::string ="");

    double height() const; //function that returns the height of the prism
    virtual double lateralSurface() const; //function that returns the surface of the solid, excluding the area of its base and top faces
    virtual int faceCount() const;
    virtual int edgeCount() const;
    virtual double surface() const;
    virtual double volume() const;

    virtual SimplePolygon* baseShape() const =0; //function that returns the base (and top) plane shape; used for 3D->2D conversion

    virtual Point3* centreOfSymmetry() const;
};

#endif // RIGHTPRISM_H
