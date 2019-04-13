//
// Created by Bertral on 09/04/2019.
//

#ifndef CFLAMEMAKER_PALETTE_H
#define CFLAMEMAKER_PALETTE_H

#include "Color.h"
#include <vector>

class Palette {
public:
    const Color color_for_index(double index) const;
    virtual ~Palette() = default;

protected:
    std::vector<Color> palette;
};


#endif //CFLAMEMAKER_PALETTE_H
