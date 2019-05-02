//
// Created by Bertral on 09/04/2019.
//

#ifndef CFLAMEMAKER_COLOR_H
#define CFLAMEMAKER_COLOR_H

class Color {
public:
    static Color BLACK;
    static Color WHITE;
    static Color RED;
    static Color GREEN;
    static Color BLUE;

    /**
     * Constructor for an RGB color, each arg must be between 0 and 1 (inclusive)
     * @param r
     * @param g
     * @param b
     */
    Color(double r, double g, double b);


    double get_r() const;
    double get_g() const;
    double get_b() const;

    /**
     *  Mix 2 colors and return the resulting colors
     * @param other Color
     * @param p weight of color "other" in the mix (between 0 and 1)
     * @return new Color
     */
    const Color mix_with(const Color &other, double p) const;

    /**
     * Used in GUI
     * @return rgb code as an int
     */
    unsigned int packed_rgb() const;

    /**
     * Gamma-encode an input color value given a max value
     * @param v r, g or b value
     * @param max max value
     * @return new value
     */
    static unsigned int srgb_encode(double v, unsigned int max);

private:
    const double r, g, b;
};


#endif //CFLAMEMAKER_COLOR_H
