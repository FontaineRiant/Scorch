//
// Created by Bertral on 09/04/2019.
//

#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(const Point &center, double width, double height) : center(center), width(width), height(height) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("rectangle dimensions must be greater than 0");
    }
}

double Rectangle::left() const {
    return center.get_x() - (width / 2);
}

double Rectangle::right() const {
    return center.get_x() + (width / 2);
}

double Rectangle::bottom() const {
    return center.get_y() - (height / 2);
}

double Rectangle::top() const {
    return center.get_y() + (height / 2);
}

double Rectangle::get_width() const {
    return width;
}

double Rectangle::get_height() const {
    return height;
}

const Point &Rectangle::get_center() const {
    return center;
}

bool Rectangle::contains(const Point &p) const {
    return p.get_x() >= left() && p.get_x() < right() && p.get_y() >= bottom() && p.get_y() < top();
}

double Rectangle::aspect_ratio() const {
    return width / height;
}

Rectangle Rectangle::expand_to_aspect_ratio(double aspect_ratio) const {

    if (aspect_ratio <= 0) {
        throw std::invalid_argument("new aspect ratio must be greater than 0");
    }

    if (aspect_ratio > this->aspect_ratio()) {
        return Rectangle(center, height * aspect_ratio, height);
    } else if (aspect_ratio < this->aspect_ratio()) {
        return Rectangle(center, width, 1 / aspect_ratio * width);
    } else {
        return Rectangle(center, width, height);
    }
}

Rectangle::Rectangle(const Rectangle& other) : height(other.height), width(other.width), center(other.center) {

}
