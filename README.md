# Nearest-centroid classification in C++ (CS2 exercise)

A small C++ exercise demonstrating a 2D `Point` class and **nearest-centroid classification**. Two groups of 200 simulated points are sampled from different coordinate ranges. Twenty query points are assigned to whichever group's arithmetic-mean point is closer; a tie is assigned to group A. This is a demonstration, **not a trained or evaluated machine-learning classifier**.

## Build and run

Requires a C++17 compiler and CMake 3.16 or later:

```sh
cmake -S . -B build
cmake --build build
./build/cs2_demo
ctest --test-dir build --output-on-failure
```

The demo prints one labelled query per line. A fixed random-engine seed makes repeated runs consistent with the same standard-library implementation; output is not guaranteed identical across different C++ libraries.

## How it works

- [`Point.h`](Point.h) / [`Point.cpp`](Point.cpp): 2D coordinates, getters/setters, display, and Euclidean distance.
- [`Classification.h`](Classification.h) / [`Classification.cpp`](Classification.cpp): arithmetic-mean centroid and nearest-centroid assignment; reject empty or null groups.
- [`c++.cpp`](c%2B%2B.cpp): synthetic-data generation and 20-query example.
- [`tests/test_classification.cpp`](tests/test_classification.cpp): normal, tie, and invalid-input cases.
- [`report.docx`](report.docx): original course report, retained unchanged. The report's contents have not been independently verified against the revised demonstration.

Group A uses x/y coordinates in [70, 90], group B in [20, 40], and queries in [5, 100]. These synthetic ranges make the exercise easy to inspect; they do not demonstrate predictive accuracy on real-world data. The original exercise used C-style allocation and an inline `Point.cpp` include; the updated build compiles implementation files separately and uses standard containers.
