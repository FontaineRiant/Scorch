//
// Created by Bertral on 10/04/2019.
//

#ifndef CFLAMEMAKER_TRANSFORMATION_H
#define CFLAMEMAKER_TRANSFORMATION_H


#include "Point.h"

class Transformation {
public:
    virtual const Point transform_point(const Point& p) const = 0;
    virtual ~Transformation() = default;
};


#endif //CFLAMEMAKER_TRANSFORMATION_H
