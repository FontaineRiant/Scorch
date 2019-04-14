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
    unsigned int width;
    unsigned int height;
} dim2;

class FlameAccumulator {
public:

    class Builder {
    private:
        Rectangle frame;
        unsigned int width;
        unsigned int height;
        unsigned int **is_hit;
        double **color_index;

    public:
        Builder(const Rectangle &frame, unsigned int width, unsigned int height);

        void hit(const Point &p, double index);

        FlameAccumulator build();
    };


    /**
     * @return x dimension of the accumulator
     */
    unsigned int get_width() const;

    /**
     * @return y dimension of the accumulator
     */
    unsigned int get_height() const;

    /**
     * computes the light intensity of a given pixel
     * @param x
     * @param y
     * @return brightness value
     */
    double intensity(unsigned int x, unsigned int y) const;

    /**
     * computes the color of a pixel
     * @param palette
     * @param background
     * @param x
     * @param y
     * @return pixel color as rgb (r g and b are between 0 and 1)
     */
    const Color color(const Palette &palette, const Color &background, unsigned int x, unsigned int y) const;

private:
    FlameAccumulator(dim2 dims, unsigned int **hit_count,
                     double **color_index_sum);

    unsigned int **hit_count;
    double **color_index_sum;
    dim2 dims;
    unsigned int max_hit_count;
};


#endif //CFLAMEMAKER_FLAMEACCUMULATOR_H
