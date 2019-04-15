#include <iostream>
#include <fstream>
#include "geometry2d/Point.h"
#include "geometry2d/Rectangle.h"
#include "flame/FlameTransformation.h"
#include "flame/Flame.h"
#include "color/InterpolatedPalette.h"

using namespace std;

int main() {

    const string FILENAME = "flame";
    dim2 dims;
    dims.width  = 1920; // Définit les dimensions de l'image
    dims.height = 1200;
    const Point CENTER_POINT(Point(-0.4, 0.0));
    const Rectangle RECTANGLE(CENTER_POINT, 5.0, 4.0); // flame dimensions


    ofstream prints;
    prints.open("output/" + FILENAME + ".ppm");

    vector<FlameTransformation> list;


    double p1[6];
    double p2[6];
    double p3[6];

    p1[0] = 1;
    p1[1] = 0.1;
    p1[2] = 0;
    p1[3] = 0;
    p1[4] = 0;
    p1[5] = 0;

    p2[0] = 0;
    p2[1] = 0;
    p2[2] = 0;
    p2[3] = 0;
    p2[4] = 0.8;
    p2[5] = 1;

    p3[0] = 1;
    p3[1] = 0;
    p3[2] = 0;
    p3[3] = 0;
    p3[4] = 0;
    p3[5] = 0;

    list.emplace_back(FlameTransformation(AffineTransformation(-0.4113504,
                                                              -0.7124804, -0.4, 0.7124795, -0.4113508, 0.8), p1));
    list.emplace_back(FlameTransformation(AffineTransformation(-0.3957339,
                                                              0, -1.6, 0, -0.3957337, 0.2), p2));
    list.emplace_back(FlameTransformation(AffineTransformation(0.4810169, 0,
                                                              1, 0, 0.4810169, 0.9), p3));


    Flame flame(list);


//    double startTime = System.currentTimeMillis();
    FlameAccumulator fractal = flame.compute(RECTANGLE, dims, 50);
//    double completionTime = System.currentTimeMillis() - startTime;

//    System.out.println(FILENAME + " : greyscale flame computed in " + completionTime + " ms");
//
//    startTime = System.currentTimeMillis();

    vector<Color> colorList;
    colorList.emplace_back(Color::RED);
    colorList.emplace_back(Color::GREEN);
    colorList.emplace_back(Color::BLUE);

    Palette palette = InterpolatedPalette(colorList);
    Color background(0, 0, 0);

    prints << "P3" << endl;
    prints << dims.width << " " << dims.height << endl;
    prints << "255" << endl;


    for (int i = 0; i < dims.height; i++) {
        for (int j = 0; j < dims.width; j++) {
            Color color = fractal.color(palette, background, j, fractal.get_height() - 1 - i);

            prints << Color::srgb_encode(color.get_r(), 255) << " "
                         << Color::srgb_encode(color.get_g(), 255) << " "
                         << Color::srgb_encode(color.get_b(), 255) << " ";
        }
        prints << endl;
    }
    prints.close();

//    completionTime = System.currentTimeMillis() - startTime;
//
//    System.out.println(FILENAME + " : flame colorized in " + completionTime + " ms");
}