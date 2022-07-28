//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_SQUARE_H
#define CANDYCRUSH_SQUARE_H


#include <FL/Enumerations.H>
#include "Coord.h"


class Square {
    public:
    Point center;
    int l;
    Fl_Color fillColor=FL_WHITE, frameColor=FL_BLACK;
    void draw();
    void setFillColor(Fl_Color newFillColor);
    void setFrameColor(Fl_Color newFrameColor);
    bool contains(Coord p);
    Square(Point centerPoint);

    Square() = default;

};


#endif //CANDYCRUSH_SQUARE_H
