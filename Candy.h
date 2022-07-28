//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_CANDY_H
#define CANDYCRUSH_CANDY_H


#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include "Coord.h"
#include "CandyRNG.h"
#include "Square.h"

class Candy {
    std::vector<int> emptyBlackList;
public:
    Point center{};
    int candyType{};
    Fl_Color candyColor{};
    int length = defaultCandyLength;
    void draw();

    explicit Candy(Point centerPoint);

    Candy() = default;

    void resetLength();

    void setCandyType(int candyType);

    void calculateColor();

    void shuffleType();
};


#endif //CANDYCRUSH_CANDY_H
