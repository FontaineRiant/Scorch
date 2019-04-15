//
// Created by Bertral on 14/04/2019.
//

#include <random>
#include <ctime>
#include "Flame.h"

Flame::Flame(const std::vector<FlameTransformation> &transformations) {
    for(unsigned int i = 0; i < transformations.size(); i++) {
        this->list.push_back(transformations.at(i));
    }
}

FlameAccumulator Flame::compute(const Rectangle &frame, dim2 dims, unsigned int density) const {
    Point* p = new Point(0, 0);

    std::uniform_int_distribution<unsigned int> unif(0, list.size() - 1);
    std::default_random_engine re(time(nullptr));
    FlameAccumulator building(dims, frame);
    double index = 0.0;

    unsigned int j;
    unsigned int iterations = density * dims.width * dims.height;
    for(unsigned int i = 0; i < iterations; i++) {
        j = unif(re);

        Point* new_p = new Point(list.at(j).transform_point(*p));
        delete p;

        p = new_p;

        index = (c(j) + index) / 2;

        building.hit(*p, index);
    }

    delete p;

    return building;
}

double Flame::c(unsigned int j) const {
    if (j == 0 || j == 1) {
        return j;
    } else {
        double d = pow(2, (unsigned int) ceil((log(j)) / log(2)));
        return ((2 * j - 1) % (unsigned int) d) / d;
    }
}
