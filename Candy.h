//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_CANDY_H
#define CANDYCRUSH_CANDY_H


#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include "Coord.h"
#include "ConstantsCC.h"
#include "candyRNG.h"

class Candy {
public:
    int candyType;
    Fl_Color candyColor;
    Coord center;
    int radius = (windowHeight+windowWidth)/30;
    Candy(Coord location);
    Candy(int candyType, Coord location);
    Candy() = default;

    int getCandyType() const;

    void setCandyType(int candyType);

    void calculateColor();

    void draw();
};


#endif //CANDYCRUSH_CANDY_H
