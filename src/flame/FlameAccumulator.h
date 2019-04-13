//
// Created by Bertral on 13/04/2019.
//

#ifndef CFLAMEMAKER_FLAMEACCUMULATOR_H
#define CFLAMEMAKER_FLAMEACCUMULATOR_H

#include <cstddef>
#include "../color/Color.h"
#include "../color/Palette.h"
#include "../geometry2d/Rectangle.h"

typedef struct {
    size_t width;
    size_t height;
} dim2;

class FlameAccumulator {
public:

    class Builder {
    private:
        Rectangle frame;
        size_t width;
        size_t height;
        unsigned int **is_hit;
        double **color_index;

    public:
        Builder(const Rectangle &frame, size_t width, size_t height);

        void hit(const Point &p, double index);

        FlameAccumulator build();
    };


    /**
     * @return x dimension of the accumulator
     */
    size_t get_width() const;

    /**
     * @return y dimension of the accumulator
     */
    size_t get_height() const;

    /**
     * computes the light intensity of a given pixel
     * @param x
     * @param y
     * @return brightness value
     */
    double intensity(size_t x, size_t y) const;

    /**
     * computes the color of a pixel
     * @param palette
     * @param background
     * @param x
     * @param y
     * @return pixel color as rgb (r g and b are between 0 and 1)
     */
    const Color color(const Palette &palette, const Color &background, size_t x, size_t y) const;

private:
    FlameAccumulator(dim2 dims, unsigned int **hit_count,
                     double **color_index_sum);

    unsigned int **hit_count;
    double **color_index_sum;
    dim2 dims;
    unsigned int max_hit_count;
};


#endif //CFLAMEMAKER_FLAMEACCUMULATOR_H
