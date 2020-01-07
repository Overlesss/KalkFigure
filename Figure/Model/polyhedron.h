#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "solid.h"


//Class that represents a solid with flat polygonal faces, straight edges and sharp vertices
class Polyhedron : public Solid
{
public:
    Polyhedron(std::string ="");

    int vertexCount() const; //function that returns the number of vertices
    virtual int faceCount() const =0; //function that returns the number of faces
    virtual int edgeCount() const =0; //function that returns the number of edges
};

#endif // POLYHEDRON_H
