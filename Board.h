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
    Cell *boardCells[9][9];

    bool swapCandy(Coord c1, Coord c2);
    void generateCandy(Coord c1);
    void deleteCandy(Coord c1);


    //bool checkStrike(Coord c1);
    //bool actionsExists();
    //void animateShift(Coord c1, Coord c2);
    //void animateShrink(Coord c1);
    //void sinkCandy(Coord c1);

};


#endif //CANDYCRUSH_BOARD_H
