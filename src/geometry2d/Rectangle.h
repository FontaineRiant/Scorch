//
// Created by Bertral on 09/04/2019.
//

#ifndef CFLAMEMAKER_RECTANGLE_H
#define CFLAMEMAKER_RECTANGLE_H


#include "Point.h"

class Rectangle {
public:
    Rectangle(const Point& center, double width, double height);
    Rectangle(const Rectangle& other);

    /**
     * @return x coordinate for the left border
     */
    double left() const;

    /**
     * @return x coordinate for the right border
     */
    double right() const;

    /**
     * @return y coordinate for the bottom border
     */
    double bottom() const;

    /**
     * @return y coordinate for the top border
     */
    double top() const;

    double get_width() const;
    double get_height() const;
    const Point& get_center() const;

    /**
     * Returns true if and only if the rectangle contains p
     * (borders included left and bottom, excluded right and top)
     *
     * @param p Point
     * @return bool
     */
    bool contains(const Point& p) const;

    /**
     * @return width/height
     */
    double aspect_ratio() const;

    /**
     * Builds a new rectangle increasing width OR height to fit new aspect ratio
     * @param aspect_ratio
     * @return new Rectangle
     */
    Rectangle expand_to_aspect_ratio(double aspect_ratio) const;

private:
    const Point& center;
    const double height, width;
};


#endif //CFLAMEMAKER_RECTANGLE_H
