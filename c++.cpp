#include "Classification.h"

#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

int main() {
    constexpr std::size_t kGroupSize = 200;
    constexpr std::size_t kQueryCount = 20;
    // Fixed seed makes the demo repeatable for a given C++ library implementation.
    std::mt19937 random_engine(2023);
    std::uniform_int_distribution<int> group_a_coordinate(70, 90);
    std::uniform_int_distribution<int> group_b_coordinate(20, 40);
    std::uniform_int_distribution<int> query_coordinate(5, 100);

    std::vector<Point> group_a;
    std::vector<Point> group_b;
    std::vector<Point> queries;
    group_a.reserve(kGroupSize);
    group_b.reserve(kGroupSize);
    queries.reserve(kQueryCount);

    for (std::size_t i = 0; i < kGroupSize; ++i) {
        group_a.emplace_back(group_a_coordinate(random_engine),
                             group_a_coordinate(random_engine));
        group_b.emplace_back(group_b_coordinate(random_engine),
                             group_b_coordinate(random_engine));
        if (i < kQueryCount) {
            queries.emplace_back(query_coordinate(random_engine),
                                 query_coordinate(random_engine));
        }
    }

    for (std::size_t i = 0; i < queries.size(); ++i) {
        std::cout << "Query " << i + 1 << ' ';
        queries[i].Display();
        std::cout << " -> "
                  << classifyNearestCentroid(queries[i], group_a.data(),
                                             group_b.data(), group_a.size())
                  << '\n';
    }
}
