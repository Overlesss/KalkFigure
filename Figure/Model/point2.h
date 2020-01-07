#ifndef POINT2_H
#define POINT2_H

#include <string>


//Class that represents an ordered pair (x, y) in the two-dimensional Euclidean space, where the first one represents the horizontal (x), and the second one represents the vertical (y)
class Point2
{
private:
    double x; //x represents the abscissa
    double y; //y represents the ordinate
public:
    Point2(double =0, double =0); //constructor with two double type parameters, both with default values, which represent the x and y values respectively
    virtual ~Point2(); //virtual destructor

    double getX() const; //function that returns the x value of a point
    double getY() const; //function that returns the y value of a point
    static double distance(const Point2&, const Point2&); //function that returns the distance between two points
    virtual std::string toString() const; //function that returns the string representation of a point
};

#endif // POINT2_H
