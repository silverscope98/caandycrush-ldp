//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_SQUARE_H
#define CANDYCRUSH_SQUARE_H


#include <FL/Enumerations.H>
#include "Coord.h"


class Square {
    public:
    Coord center;
    int l;
    Fl_Color fillColor=FL_BLACK, frameColor=FL_WHITE;
    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    bool contains(Coord p);
    Square(Coord centerPoint);

    Square(Coord center, int l, Fl_Color fillColor, Fl_Color frameColor);
    Square() = default;

};


#endif //CANDYCRUSH_SQUARE_H
