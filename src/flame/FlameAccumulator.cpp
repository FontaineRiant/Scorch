//
// Created by Bertral on 13/04/2019.
//

#include <stdexcept>
#include <cmath>
#include "FlameAccumulator.h"

FlameAccumulator::FlameAccumulator(dim2 dims, unsigned int **hit_count,
                                   double **color_index_sum) {
    this->hit_count[dims.width][dims.height];
    this->color_index_sum[dims.width][dims.height];
    this->dims.width = dims.width;
    this->dims.height = dims.height;
    this->max_hit_count = 0;

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

FlameAccumulator::Builder::Builder(const Rectangle &frame, unsigned int width, unsigned int height)
        : height(height), width(width), frame(frame) {
    if (width < 0 || height < 0) {
        throw std::invalid_argument("FlameAccumulator::Builder : height and width must be strictly positive");
    }

    is_hit = new unsigned int*[width];
    for(unsigned int i = 0; i < width; i++) {
        is_hit[i] = new unsigned int[height];
    }

    color_index[width][height];
}

void FlameAccumulator::Builder::hit(const Point &p, double index) {
    if(frame.contains(p)) {
        unsigned int x = (unsigned int) ((p.get_x() - frame.left()) / (frame.get_width() / width));
        unsigned int y = (unsigned int) ((p.get_y() - frame.bottom()) / (frame.get_height() / height));

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
