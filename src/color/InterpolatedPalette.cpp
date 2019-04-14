//
// Created by Bertral on 09/04/2019.
//

#include <stdexcept>
#include "InterpolatedPalette.h"

InterpolatedPalette::InterpolatedPalette(std::vector<Color> palette) {
    const unsigned int N = palette.size();

    if(N < 2) {
        throw std::invalid_argument("new palette must contain at least 2 colors");
    }

    for(unsigned int i = 0; i < N; i++) {
        this->palette.push_back(palette.at(i));
    }
}
