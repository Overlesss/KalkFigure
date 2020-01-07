#include "simplepolygon.h"


SimplePolygon::SimplePolygon(std::string n) : Plane(n) {}


int SimplePolygon::vertexCount() const {
    return getPoints().size();
}


Point2* SimplePolygon::centreOfSymmetry() const {
    const std::vector<Point2> vP = getPoints();
    double centroidX = 0.0, centroidY = 0.0; //centroid X and Y coordinates
    double signedArea = 0.0;
    double aux = 0.0;  // partial signed area
    double x0 = 0.0; // current vertex X
    double y0 = 0.0; // current vertex Y
    double x1 = 0.0; // next vertex X
    double y1 = 0.0; // next vertex Y

    for (int i = 0; i < vertexCount(); ++i) {
        x0 = vP[i].getX();
        y0 = vP[i].getY();
        x1 = vP[(i+1) % vertexCount()].getY();
        y1 = vP[(i+1) % vertexCount()].getY();
        aux = x0 * y1 - x1 * y0;
        signedArea += aux;
        centroidX += (x0 + x1) * aux;
        centroidY += (y0 + y1) * aux;
    }

    signedArea *= 0.5;
    centroidX /= (6.0 * signedArea);
    centroidY /= (6.0 * signedArea);

    return new Point2(centroidX, centroidY);
}


double SimplePolygon::perimeter() const {
    const std::vector<Point2> vP = getPoints();
    double p = 0.0;
    Point2 p0, p1;

    for (int i = 0; i < vertexCount(); ++i) {
        p0 = vP[i];
        p1 = vP[(i+1) % vertexCount()];
        p += Point2::distance(p0, p1);
    }
    return p;
}


double SimplePolygon::area() const {
    const std::vector<Point2> vP = getPoints();
    double signedArea = 0.0;
    double x0 = 0.0; // current vertex X
    double y0 = 0.0; // current vertex Y
    double x1 = 0.0; // next vertex X
    double y1 = 0.0; // next vertex Y

    for (int i = 0; i < vertexCount(); ++i) {
        x0 = vP[i].getX();
        y0 = vP[i].getY();
        x1 = vP[(i+1) % vertexCount()].getX();
        y1 = vP[(i+1) % vertexCount()].getY();
        signedArea += x0 * y1 - x1 * y0;
    }

    return 0.5 * signedArea;
}
