#include <cmath>
#include <iostream>
#include <string>

#include "point2.h"

Point2::Point2 (float newX, float newY) {
    x = newX;
    y = newY;
}

// This appears to work correctly
float Point2::DistanceBetween(Point2 other) {
    // float distance;
    // distance = sqrt( (other.x - this.x) + (other.y - this.y) );
    // this.x
    // other.x

    return sqrt( pow((other.x - this->x), 2.0) + pow((other.y - this->y), 2.0) );
}

// 50 x 50 grid, how to manage the axis? Start ccw with the east axis.
// This appears to work correctly.
int Point2::Quadrant() {
    if (x > 0 && y >= 0) {
        return 1;
    } 
    if (x <= 0 && y > 0) {
        return 2;
    }
    if (x < 0 && y <= 0) {
        return 3;
    }
    if (x >= 0 && y < 0) {
        return 4;
    }
    if (x == 0 && y == 0) {
        return 0;
    }
    return -1;
}

// This appears to work correctly.
void Point2::Print() {
    std::cout << "(" << x << ", " << y << ")";
}