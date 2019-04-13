//
// Created by Bertral on 10/04/2019.
//

#ifndef CFLAMEMAKER_FLAMETRANSFORMATION_H
#define CFLAMEMAKER_FLAMETRANSFORMATION_H

#define N_TRANSFORMATIONS 6

#include "../geometry2d/AffineTransformation.h"
#include "../geometry2d/Transformation.h"
#include "Variation.h"

class FlameTransformation : public Transformation {
public:
    class Builder {
    public:
        explicit Builder(FlameTransformation& flame_trans);
        const AffineTransformation& get_affine_comp() const;
        void set_affine_comp(const AffineTransformation& new_trans);
        double get_weight(const Variation& variation) const;
        void set_weight(const Variation&  variation, double new_weight);

    private:
        FlameTransformation& flame_trans;
    };

    /**
     * weights must contain exactly 6 numbers
     * @param aff_trans
     * @param weights
     * @param n_weights
     */
    FlameTransformation(const AffineTransformation& aff_trans, double weights[]);
    const Point transform_point(const Point& p) const override;

private:
    AffineTransformation aff_trans;
    double weights[];
};


#endif //CFLAMEMAKER_FLAMETRANSFORMATION_H
