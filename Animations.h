//
// Created by hars on 26/07/22.
//

#ifndef CANDYCRUSH_ANIMATIONS_H
#define CANDYCRUSH_ANIMATIONS_H


#include "Cell.h"
#include "Board.h"

class Animations {
public:
    Board &board;
    Animations(Board &board);

    void shrinkCandies(std::vector<Coord> &targets);

    [[maybe_unused]] void shrinkCandy(Coord target);


    void intersectCandy(Coord c1, Coord c2, int speedMultiplier);

    void restoreCandy(Coord c1, Coord c2, int speedMultiplier);
};


#endif //CANDYCRUSH_ANIMATIONS_H
