//
// Created by Bertral on 08/04/2019.
//

#ifndef CFLAMEMAKER_POINT_H
#define CFLAMEMAKER_POINT_H


class Point {
public:
    Point(double x, double y);

    double get_x() const;
    double get_y() const;

    /**
     *
     * @return polar coordinate r
     */
    double theta() const;

    /**
     *
     * @return polar coordinate theta
     */
    double r() const;

private:
    const double x, y;
};


#endif //CFLAMEMAKER_POINT_H
