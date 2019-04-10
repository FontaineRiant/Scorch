//
// Created by Bertral on 09/04/2019.
//

#include <stdexcept>
#include <random>
#include "time.h"
#include "RandomPalette.h"

RandomPalette::RandomPalette(size_t nColors) {
    if (nColors < 2) {
        throw std::invalid_argument("new palette must contain at least 2 colors");
    }

    std::uniform_real_distribution<double> unif(0.0, 1.0);
    std::default_random_engine re(time(nullptr));

    for (size_t i = 0; i < nColors; i++) {
        this->palette.push_back(Color(unif(re), unif(re), unif(re)));
    }
}
