//
// Created by Bertral on 13/04/2019.
//

#include <stdexcept>
#include <cmath>
#include "FlameAccumulator.h"

FlameAccumulator::FlameAccumulator(dim2 dims, unsigned int **hit_count,
                                   double **color_index_sum) {
    this->hit_count[dims.height][dims.width];
    this->color_index_sum[dims.height][dims.width];
    this->dims.width = dims.width;
    this->dims.height = dims.height;
    this->max_hit_count = 0;

    for (size_t i = 0; i < dims.height; i++) {
        for (size_t j = 0; j < dims.width; j++) {
            this->color_index_sum[i][j] = color_index_sum[i][j];
            this->hit_count[i][j] = hit_count[i][j];

            if (max_hit_count < hit_count[i][j]) {
                max_hit_count = hit_count[i][j];
            }
        }
    }
}

double FlameAccumulator::intensity(size_t x, size_t y) const {
    if (x < 0 || x >= dims.height) {
        throw std::out_of_range("FlameAccumulator::intensity : x out of range");
    }

    if (y < 0 || y >= dims.width) {
        throw std::out_of_range("FlameAccumulator::intensity : y out of range");
    }

    return log(hit_count[x][y] + 1) / log(max_hit_count + 1);
}

size_t FlameAccumulator::get_width() const {
    return dims.width;
}

size_t FlameAccumulator::get_height() const {
    return dims.height;
}

const Color FlameAccumulator::color(const Palette &palette, const Color &background, size_t x, size_t y) const {
    if (x < 0 || x >= dims.height) {
        throw std::out_of_range("FlameAccumulator::intensity : x out of range");
    }

    if (y < 0 || y >= dims.width) {
        throw std::out_of_range("FlameAccumulator::intensity : y out of range");
    }

    if (hit_count[x][y] == 0) {
        return background;
    } else {
        return palette.color_for_index(color_index_sum[x][y] / hit_count[x][y]).mix_with(background,
                                                                                         1 - intensity(x, y));
    }
}

FlameAccumulator::Builder::Builder(const Rectangle &frame, size_t width, size_t height)
        : height(height), width(width), frame(frame) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("FlameAccumulator::Builder : height and width must be strictly positive");
    }

    is_hit[width][height];
    color_index[width][height];
}

void FlameAccumulator::Builder::hit(const Point &p, double index) {
    if(frame.contains(p)) {
        size_t x = (size_t) ((p.get_x() - frame.left()) / (frame.get_width() / width));
        size_t y = (size_t) ((p.get_y() - frame.bottom()) / (frame.get_height() / height));

        is_hit[x][y]++;
        color_index[x][y] += index;
    }
}

FlameAccumulator FlameAccumulator::Builder::build() {
    dim2 dim;
    dim.width = width;
    dim.height = height;
    return FlameAccumulator(dim, is_hit, color_index);
}
