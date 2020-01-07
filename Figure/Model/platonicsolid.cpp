#include "platonicsolid.h"
#include <math.h>


PlatonicSolid::PlatonicSolid(std::string n) : Polyhedron(n) {}


int PlatonicSolid::schlafliSymbol_p() const {
    return face()->vertexCount();
}


std::string PlatonicSolid::schlafliSymbol() const {
    std::string s = "{" + std::to_string(schlafliSymbol_p()) + "," + std::to_string(schlafliSymbol_q()) + "}";
    return s;
}


double PlatonicSolid::edge() const {
    return Point3::distance(getPoints()[0], getPoints()[1]);
}


int PlatonicSolid::faceCount() const {
    return schlafliSymbol_q() * vertexCount() / schlafliSymbol_p();
}


int PlatonicSolid::edgeCount() const {
    return faceCount() + vertexCount() - 2;
}


double PlatonicSolid::surface() const {
    const double PI = atan(1) * 4;
    return pow(edge() / 2, 2) * faceCount() * schlafliSymbol_p() * (1 / tan(PI / schlafliSymbol_p()));
}

