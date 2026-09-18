#ifndef CS2_CLASSIFICATION_H
#define CS2_CLASSIFICATION_H

#include "Point.h"

#include <cstddef>

// Compute the arithmetic mean of count 2D points.
// Throws std::invalid_argument for a null pointer or an empty group.
Point centroid(const Point* points, std::size_t count);

// Return 'A' for ties, otherwise the group with the nearer centroid.
// Both groups contain count points; invalid inputs throw std::invalid_argument.
char classifyNearestCentroid(const Point& query, const Point* group_a,
                             const Point* group_b, std::size_t count);

#endif  // CS2_CLASSIFICATION_H
