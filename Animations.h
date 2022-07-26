//
// Created by hars on 26/07/22.
//

#ifndef CANDYCRUSH_ANIMATIONS_H
#define CANDYCRUSH_ANIMATIONS_H


#include "Cell.h"

class Animations {
public:
    Animations() = default;

    static void translateCandy(Cell &target, Coord endPoint);

    static void shrinkCandy(Candy &target);

    static void growCandy(Candy &target);
};


#endif //CANDYCRUSH_ANIMATIONS_H
