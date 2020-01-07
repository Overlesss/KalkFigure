#include "shape.h"


Shape::Shape(std::string n) : name(n) {}


Shape::~Shape() {}


std::string Shape::getName() const {
    return name;
}


void Shape::setName(std::string n) {
    name = n;
}
