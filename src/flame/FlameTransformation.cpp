//
// Created by Bertral on 10/04/2019.
//

#include "FlameTransformation.h"

FlameTransformation::Builder::Builder(FlameTransformation &flame_trans) : flame_trans(flame_trans) {

}

const AffineTransformation &FlameTransformation::Builder::get_affine_comp() const {
    return flame_trans.aff_trans;
}

void FlameTransformation::Builder::set_affine_comp(const AffineTransformation &new_trans) {
    flame_trans.aff_trans = new_trans;
}

double FlameTransformation::Builder::get_weight(const Variation &variation) const {
    return flame_trans.weights[variation.get_index()];
}

void FlameTransformation::Builder::set_weight(const Variation &variation, double new_weight) {
    flame_trans.weights[variation.get_index()] = new_weight;
}

FlameTransformation::FlameTransformation(const AffineTransformation &aff_trans, double *weights) :
        aff_trans(aff_trans) {
    for (unsigned int i = 0; i < N_TRANSFORMATIONS; i++) {
        this->weights[i] = weights[i];
    }
}

Point FlameTransformation::transform_point(const Point &p) const {

    double x = 0;
    double y = 0;

    for (unsigned int i = 0; i < N_TRANSFORMATIONS; i++) {
        if (weights[i] != 0) { // avoid computing useless things that will get multiplied by 0
            x += Variation::ALL_VARIATIONS.at(i)->transform_point(aff_trans.transform_point(p))
                         .get_x() * weights[i];
            y += Variation::ALL_VARIATIONS.at(i)->transform_point(aff_trans.transform_point(p))
                         .get_y() * weights[i];
        }
    }
    return Point(x, y);
}
