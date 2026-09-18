#include "Point.h"

#include <cmath>
#include <iostream>

Point::Point() : x(0), y(0) {}
Point::Point(float x_value, float y_value) : x(x_value), y(y_value) {}

void Point::setX(float x_value) { x = x_value; }
void Point::setY(float y_value) { y = y_value; }
float Point::getX() const { return x; }
float Point::getY() const { return y; }
void Point::Display() const { std::cout << '(' << x << ", " << y << ')'; }
float Point::distance(const Point& other) const {
    return std::hypot(x - other.x, y - other.y);
}
