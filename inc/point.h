#ifndef ADVENT_POINT_H
#define ADVENT_POINT_H

#include <ostream>

namespace advent::utility::point {
struct Point {
    int64_t x;
    int64_t y;

    static Point from(const std::string& source);
};

Point rotateRight(const Point& source);

bool operator==(const Point& a, const Point& b);

bool operator!=(const Point& a, const Point& b);

bool operator<(const Point& a, const Point& b);

std::ostream& operator<<(std::ostream& os, const Point& p);

Point operator+(const Point& a, const Point& b);

Point operator+=(Point& self, const Point& other);

Point operator*(const Point& a, int64_t b);
} // namespace advent::utility::point

#endif
