//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_BOARD_H
#define CANDYCRUSH_BOARD_H


#include "Cell.h"

class Board {
public:
    Board();
    void draw();
    Cell boardCells[9][9];

    Cell& getCell(Coord target);
    std::vector<Coord> cellsOnPath(int range, Coord target, int xDir, int yDir);
    std::vector<Coord> getAboveCells(int range, Coord target);
    std::vector<Coord> getBelowCells(int range, Coord target);
    std::vector<Coord> getLeftCells(int range, Coord target);
    std::vector<Coord> getRightCells(int range, Coord target);
    void setCandyType(Coord target, int candyType);
    Candy& getCandy(Coord target);
    int getCandyType(Coord target);
    void generateDisjointCandy(Coord c1);
};

#endif //CANDYCRUSH_BOARD_H
