//
// Created by Bertral on 09/04/2019.
//

#include <cmath>
#include "Palette.h"

const Color Palette::color_for_index(double index) const {

    // Agrandit l'index proportionnellement la taille de la palette. Ainsi chaque couleur non-mélangée
    // correspond à un nombre entier. Stock cet index dans la variable indexn.
    double indexn = index * (palette.size() - 1);

    // La couleur non-mélangée se trouvant à gauche de l'index dans la palette.
    int couleurinf = (int) floor(indexn);

    // La couleur non-mélangée se trouvant à droite de l'index dans la palette.
    int couleursup = (int) ceil(indexn);

    if (couleurinf == couleursup) {
        return palette.at((int) indexn);
    } else {
        return palette.at(couleurinf).mix_with(palette.at(couleursup), indexn - couleurinf);
    }
}
