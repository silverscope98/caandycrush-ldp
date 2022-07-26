//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_CELL_H
#define CANDYCRUSH_CELL_H


#include "Coord.h"
#include "Square.h"
#include "Candy.h"

class Cell {

public:
    Coord cellCoord;
    Coord pixelPoint;
    Cell(int x, int y);
    void draw();

    Cell() = default;
    Candy candy;

    Square sq;

};


#endif //CANDYCRUSH_CELL_H
