//
// Created by Bertral on 10/04/2019.
//

#ifndef CFLAMEMAKER_FLAMETRANSFORMATION_H
#define CFLAMEMAKER_FLAMETRANSFORMATION_H

#include "../geometry2d/AffineTransformation.h"
#include "../geometry2d/Transformation.h"
#include "Variation.h"

class FlameTransformation : public Transformation {
public:
    static class Builder {
    public:
        Builder(FlameTransformation& flame_trans);
        const AffineTransformation& get_affine_comp() const;
        void set_affine_comp(const AffineTransformation& new_trans);
        double get_weight(Variation variation) const;
        void set_weight(Variation variation, double new_weight);

    private:
        FlameTransformation& flame_trans;
    };

    FlameTransformation(const AffineTransformation& aff_trans, double weights[]);
    const Point transform_point(const Point& p) const;

private:
    AffineTransformation aff_trans;
    double weight[];
};


#endif //CFLAMEMAKER_FLAMETRANSFORMATION_H
