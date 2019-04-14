//
// Created by Bertral on 08/04/2019.
//

#include "Point.h"
#include <cmath>

Point::Point(double x, double y) : x(x), y(y){

}

double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}

double Point::theta() const {
    return atan2(x, y);
}

double Point::r() const {
    return sqrt(x * x + y * y);
}

Point::Point(const Point &other) : x(other.x), y(other.y) {

}
