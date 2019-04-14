//
// Created by Bertral on 09/04/2019.
//

#include <cmath>
#include "AffineTransformation.h"


AffineTransformation::AffineTransformation(double a, double b, double c, double d, double e, double f) :
        a(a), b(b), c(c), d(d), e(e), f(f) {

}

AffineTransformation::AffineTransformation(const AffineTransformation &t) :
        a(t.a), b(t.b), c(t.c), d(t.d), e(t.e), f(t.f) {

}

AffineTransformation AffineTransformation::translation(double dx, double dy) {
    return AffineTransformation(1.0, 0.0, dx, 0.0, 1.0, dy);
}

AffineTransformation AffineTransformation::rotation(double theta) {
    return AffineTransformation(cos(theta), -(sin(theta)), 0,
                                sin(theta), cos(theta), 0);
}

AffineTransformation AffineTransformation::scaling(double sx, double sy) {
    return AffineTransformation(sx, 0, 0, 0, sy, 0);
}

AffineTransformation AffineTransformation::shear_x(double sx) {
    return AffineTransformation(1, sx, 0, 0, 1, 0);
}

AffineTransformation AffineTransformation::shear_y(double sy) {
    return AffineTransformation(1, 0, 0, sy, 1, 0);
}

Point AffineTransformation::transform_point(const Point &p) const {
    return Point(p.get_x() * a + p.get_y() * b + c, p.get_x() * d + p.get_y() * e + f);
}

double AffineTransformation::get_translation_x() const {
    return c;
}

double AffineTransformation::get_translation_y() const {
    return f;
}

const AffineTransformation AffineTransformation::compose_with(const AffineTransformation &that) const {
    return AffineTransformation(a * that.a + b * that.d, a * that.b + b * that.e, a * that.c + b * that.e + c,
                                d * that.a + e * that.d, d * that.b + e * that.e, d * that.c + e * that.f + f);
}
