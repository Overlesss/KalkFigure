#ifndef PLATONICSOLID_H
#define PLATONICSOLID_H

#include "polyhedron.h"
#include "regularpolygon.h"


//Class that represents a regular and convex polyhedron, with the same number of congruent regular polygonal faces meeting at each vertex
class PlatonicSolid : public Polyhedron
{
private:
    virtual void createShape(const Plane*) =0; //function that builds a platonic solid starting from its face

protected:
    int schlafliSymbol_p() const; //function that returns the symbol p of the Schlafli Symbol
    virtual int schlafliSymbol_q() const =0; //function that returns the symbol q of the Schlafli Symbol

public:
    PlatonicSolid(std::string ="");

    /*
     * Each Platonic solid can be denoted by a symbol {p,q} where
     * p is the number of edges (or, equivalently, vertices) of each face, and
     * q is the number of faces (or, equivalently, edges) that meet at each vertex.
     * */
    virtual std::string schlafliSymbol() const;

    double edge() const; //function that returns the length of the edge
    virtual int faceCount() const;
    virtual int edgeCount() const;
    virtual double inRadius() const =0; //function that returns the length of the radius of the incircle
    virtual double circumRadius() const =0; //function that returns the length of the radius of the circumcircle
    virtual double surface() const;

    virtual RegularPolygon* face() const =0;  //function that returns the face shape; used for 3D->2D conversion
};

#endif // PLATONICSOLID_H
