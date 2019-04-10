//
// Created by Bertral on 09/04/2019.
//

#ifndef CFLAMEMAKER_AFFINETRANSFORMATION_H
#define CFLAMEMAKER_AFFINETRANSFORMATION_H


#include "Point.h"
#include "Transformation.h"

class AffineTransformation : public Transformation {
public:
    AffineTransformation(double a, double b, double c, double d, double e, double f);
    AffineTransformation(const AffineTransformation& t);

    static AffineTransformation translation(double dx, double dy);
    static AffineTransformation rotation(double theta);
    static AffineTransformation scaling(double sx, double sy);
    static AffineTransformation shear_x(double sx);
    static AffineTransformation shear_y(double sy);

    const Point transform_point(const Point& p) const;
    double get_translation_x() const;
    double get_translation_y() const;
    const AffineTransformation compose_with(const AffineTransformation& that) const;

private:
    double a, b, c, d, e, f;
};


#endif //CFLAMEMAKER_AFFINETRANSFORMATION_H
