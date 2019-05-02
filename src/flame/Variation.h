//
// Created by Bertral on 10/04/2019.
//

#ifndef CFLAMEMAKER_VARIATION_H
#define CFLAMEMAKER_VARIATION_H

#include <vector>
#include <string>
#include <cmath>
#include "../geometry2d/Transformation.h"

class Variation : public Transformation {

public:
    const std::string &get_name() const;

    unsigned int get_index() const;

    static std::vector<Variation*> ALL_VARIATIONS;

protected:
    Variation(unsigned int index, std::string name);

private:
    const std::string name;
    const unsigned int index;
};


#endif //CFLAMEMAKER_VARIATION_H
