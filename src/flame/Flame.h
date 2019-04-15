//
// Created by Bertral on 14/04/2019.
//

#ifndef CFLAMEMAKER_FLAME_H
#define CFLAMEMAKER_FLAME_H


#include "FlameTransformation.h"
#include "FlameAccumulator.h"

class Flame {
public:

    Flame(const std::vector<FlameTransformation>& transformations);

    FlameAccumulator compute(const Rectangle& frame, dim2 dims, unsigned int density) const;

private:
    double c(unsigned int j) const;

    std::vector<FlameTransformation> list;
};


#endif //CFLAMEMAKER_FLAME_H
