//
// Created by Bertral on 10/04/2019.
//

#include "FlameTransformation.h"

FlameTransformation::Builder::Builder(FlameTransformation &flame_trans) : flame_trans(flame_trans) {

}

const AffineTransformation &FlameTransformation::Builder::get_affine_comp() const {
    return <#initializer#>;
}

void FlameTransformation::Builder::set_affine_comp(const AffineTransformation &new_trans) {

}

double FlameTransformation::Builder::get_weight(Variation variation) const {
    return 0;
}

void FlameTransformation::Builder::set_weight(Variation variation, double new_weight) {

}

FlameTransformation::FlameTransformation(const AffineTransformation &aff_trans, double *weights) :
        aff_trans(aff_trans){

}

const Point FlameTransformation::transform_point(const Point &p) const {
    return Point(0, 0);
}
