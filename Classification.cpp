#include "Classification.h"

#include <stdexcept>

Point centroid(const Point* points, std::size_t count) {
    if (points == nullptr || count == 0) {
        throw std::invalid_argument("centroid requires a nonempty point array");
    }
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (std::size_t i = 0; i < count; ++i) {
        sum_x += points[i].getX();
        sum_y += points[i].getY();
    }
    return Point(static_cast<float>(sum_x / count),
                 static_cast<float>(sum_y / count));
}

char classifyNearestCentroid(const Point& query, const Point* group_a,
                             const Point* group_b, std::size_t count) {
    const Point a_center = centroid(group_a, count);
    const Point b_center = centroid(group_b, count);
    return query.distance(a_center) <= query.distance(b_center) ? 'A' : 'B';
}
