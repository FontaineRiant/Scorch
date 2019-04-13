#include <utility>

//
// Created by Bertral on 10/04/2019.
//

#include "Variation.h"

Variation::Variation(size_t index, std::string  name) : index(index), name(std::move(name)) {

}

const std::string& Variation::get_name() const {
    return name;
}

int Variation::get_index() const {
    return index;
}

// Here below is an ugly workaround to the fact that anonymous classes don't translate well from java

class LinearVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        return Point(p.get_x(), p.get_y());
    }
    LinearVariation() : Variation(0, "Linear") {}
} linear_variation;

class SinusoidalVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        return Point(sin(p.get_x()), sin(p.get_y()));
    }

    SinusoidalVariation() : Variation(1, "Sinusoidal") {}
} sinusoidal_variation;

class SphericalVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        return Point(p.get_x() / (p.r() * p.r()), p.get_y() / (p.r() * p.r()));
    }

    SphericalVariation() : Variation(2, "SphericalVariation") {}
} spherical_variation;

class SwirlVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        double temp_sin = sin(p.r() * p.r());
        double temp_cos = cos(p.r() * p.r());
        return Point((p.get_x() * temp_sin - p.get_y() * temp_cos),
                     (p.get_x() * temp_cos + p.get_y() * temp_sin));
    }

    SwirlVariation() : Variation(3, "Swirl") {}
} swirl_variation;


class HorseshoeVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        return Point((p.get_x() - p.get_y()) * (p.get_x() + p.get_y()) / p.r(),
                     2 * p.get_x() * p.get_y() / p.r());
    }

    HorseshoeVariation() : Variation(4, "Horseshoe") {}
} horseshoe_variation;

class BubbleVariation : public Variation {
public:
    const Point transform_point(const Point &p) const override {
        return Point((4 * p.get_x()) / (p.r() * p.r() + 4), (4 * p.get_y()) / (p.r() * p.r() + 4));
    }

    BubbleVariation() : Variation(5, "Bubble") {}
} bubble_variation;

std::vector<Variation*> Variation::ALL_VARIATIONS = {
    &linear_variation,
    &sinusoidal_variation,
    &spherical_variation,
    &swirl_variation,
    &horseshoe_variation,
    &bubble_variation
};