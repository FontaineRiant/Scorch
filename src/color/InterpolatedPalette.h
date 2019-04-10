//
// Created by Bertral on 09/04/2019.
//

#ifndef CFLAMEMAKER_INTERPOLATEDPALETTE_H
#define CFLAMEMAKER_INTERPOLATEDPALETTE_H

#include <vector>
#include "Palette.h"

class InterpolatedPalette : public Palette {
public:
    InterpolatedPalette(std::vector<Color> palette);
};


#endif //CFLAMEMAKER_INTERPOLATEDPALETTE_H
