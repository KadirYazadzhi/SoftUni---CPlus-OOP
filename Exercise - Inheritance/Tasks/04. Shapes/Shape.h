#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"

class Shape {
protected:
    Vector2D center;

    double area;

public:
    Shape() : center(0, 0), area(0) {};
    Shape(const Vector2D & center) : center(center), area(0) {}

    const Vector2D & getCenter(void) const {
        return center;
    }

    double getArea(void) const {
        return area;
    }
};

#endif