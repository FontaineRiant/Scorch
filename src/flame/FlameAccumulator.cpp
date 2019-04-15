//
// Created by Bertral on 13/04/2019.
//

#include <stdexcept>
#include <cmath>
#include "FlameAccumulator.h"

FlameAccumulator::FlameAccumulator(dim2 dims, const Rectangle& frame) : frame(frame), dims(dims), max_hit_count(0) {
    if (dims.width < 0 || dims.height < 0) {
        throw std::invalid_argument("FlameAccumulator : height and width must be strictly positive");
    }

    hit_count = new unsigned int*[dims.width];
    for(unsigned int i = 0; i < dims.width; i++) {
        hit_count[i] = new unsigned int[dims.height];
    }

    color_index_sum = new double*[dims.width];
    for(unsigned int i = 0; i < dims.width; i++) {
        color_index_sum[i] = new double[dims.height];
    }

    for (unsigned int i = 0; i < dims.width; i++) {
        for (unsigned int j = 0; j < dims.height; j++) {
            this->color_index_sum[i][j] = color_index_sum[i][j];
            this->hit_count[i][j] = hit_count[i][j];

            if (max_hit_count < hit_count[i][j]) {
                max_hit_count = hit_count[i][j];
            }
        }
    }
}

FlameAccumulator::~FlameAccumulator() {
    for(unsigned int i = 0; i < dims.width; i++) {
        delete hit_count[i];
    }
    delete hit_count;

    for(unsigned int i = 0; i < dims.width; i++) {
        delete color_index_sum[i];
    }
    delete color_index_sum;
}


double FlameAccumulator::intensity(unsigned int x, unsigned int y) const {
    if (x < 0 || x >= dims.width) {
        throw std::out_of_range("FlameAccumulator::intensity : x out of range");
    }

    if (y < 0 || y >= dims.height) {
        throw std::out_of_range("FlameAccumulator::intensity : y out of range");
    }

    return log(hit_count[x][y] + 1) / log(max_hit_count + 1);
}

unsigned int FlameAccumulator::get_width() const {
    return dims.width;
}

unsigned int FlameAccumulator::get_height() const {
    return dims.height;
}

const Color FlameAccumulator::color(const Palette &palette, const Color &background, unsigned int x, unsigned int y) const {
    if (x < 0 || x >= dims.width) {
        throw std::out_of_range("FlameAccumulator::intensity : x out of range");
    }

    if (y < 0 || y >= dims.height) {
        throw std::out_of_range("FlameAccumulator::intensity : y out of range");
    }

    if (hit_count[x][y] == 0) {
        return background;
    } else {
        return palette.color_for_index(color_index_sum[x][y] / hit_count[x][y]).mix_with(background,
                                                                                         1 - intensity(x, y));
    }
}

void FlameAccumulator::hit(const Point &p, double index) {
    if(frame.contains(p)) {
        unsigned int x = (p.get_x() - frame.left()) / (frame.get_width() / dims.width);
        unsigned int y = (p.get_y() - frame.bottom()) / (frame.get_height() / dims.height);

        hit_count[x][y]++;
        color_index_sum[x][y] += index;
    }
}
