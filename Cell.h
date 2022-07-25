//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H


#include "Coord.h"
#include "Square.h"
#include "Candy.h"

class Cell {
    Coord cellCoord;
    Coord pixelPoint;
    Square sq;
public:
    Cell(int x, int y);
    void draw();

    Candy candy;
};


#endif //CANDYCRUSH_CELL_H