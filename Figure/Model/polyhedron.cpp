#include "polyhedron.h"


Polyhedron::Polyhedron(std::string n) : Solid(n) {}


int Polyhedron::vertexCount() const {
    return getPoints().size();
}

