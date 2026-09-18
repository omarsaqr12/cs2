#include "Classification.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

void testPoint() {
    Point p;
    require(p.getX() == 0 && p.getY() == 0, "default point coordinates");
    p.setX(3);
    p.setY(4);
    const Point q(0, 0);
    require(std::abs(p.distance(q) - 5.0f) < 0.0001f, "Pythagorean distance");
    require(p.distance(p) == 0, "distance to self");
    std::ostringstream out;
    auto* original = std::cout.rdbuf(out.rdbuf());
    p.Display();
    std::cout.rdbuf(original);
    require(out.str() == "(3, 4)", "point display format");
}

void testCentroidAndClassification() {
    const Point a[] = {Point(0, 0), Point(2, 2)};
    const Point b[] = {Point(8, 8), Point(10, 10)};
    const Point center = centroid(a, 2);
    require(center.getX() == 1 && center.getY() == 1, "centroid mean");
    require(classifyNearestCentroid(Point(0, 0), a, b, 2) == 'A', "group A");
    require(classifyNearestCentroid(Point(10, 10), a, b, 2) == 'B', "group B");
    require(classifyNearestCentroid(Point(5, 5), a, b, 2) == 'A', "tie uses A");
}

void testInvalidInput() {
    const Point point(0, 0);
    for (int mode = 0; mode < 4; ++mode) {
        bool threw = false;
        try {
            if (mode == 0) (void)centroid(&point, 0);
            if (mode == 1) (void)centroid(nullptr, 1);
            if (mode == 2) (void)classifyNearestCentroid(point, nullptr, &point, 1);
            if (mode == 3) (void)classifyNearestCentroid(point, &point, nullptr, 1);
        } catch (const std::invalid_argument&) {
            threw = true;
        }
        require(threw, "invalid group must throw");
    }
}
}  // namespace

int main() {
    try {
        testPoint();
        testCentroidAndClassification();
        testInvalidInput();
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << error.what() << '\n';
        return 1;
    }
    std::cout << "PASS: point, centroid, nearest-centroid, ties, invalid inputs\n";
}
