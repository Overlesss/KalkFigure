#ifndef KALKEXCEPTION_H
#define KALKEXCEPTION_H

#include <string>


class KalkException
{
private:
    std::string err;
public:
    KalkException(const std::string& mess) : err(mess){}
    std::string getError() { return err; }
};


class NegativeValue : public KalkException {
    public:
    NegativeValue(const std::string& mess ="Negative values not allowed.") : KalkException(mess) {}
};


class NonPositiveValues : public KalkException {
    public:
    NonPositiveValues(const std::string& mess ="Value/values must be greater than 0.") : KalkException(mess) {}
};


class ValueOutOfRange : public KalkException {
    public:
    ValueOutOfRange(const std::string& mess ="Value out of range. It must be between 0 and 100.") : KalkException(mess) {}
};


class UnsuitableValues : public KalkException {
    public:
    UnsuitableValues(const std::string& mess ="Unsuitable values for the shape: long base must be greater that the short one.") : KalkException(mess) {}
};


class WrongShape : public KalkException {
    public:
    WrongShape(const std::string& mess ="It is not possible to build the object from the current plane shape.") : KalkException(mess) {}
};


class DifferentShapes : public KalkException {
    public:
    DifferentShapes(const std::string& mess ="The two shapes are not of the same type.") : KalkException(mess) {}
};


class CongruentShapes : public KalkException {
    public:
    CongruentShapes(const std::string& mess ="The two shapes are congruent. Their difference would delete the object.") : KalkException(mess) {}
};


class BigShape : public KalkException {
    public:
    BigShape(const std::string& mess ="The shape is too big. Cannot subtract a bigger shape from a smaller one.") : KalkException(mess) {}
};


#endif // KALKEXCEPTION_H
