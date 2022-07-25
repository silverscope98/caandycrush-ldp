//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_GAME_H
#define CANDYCRUSH_GAME_H


#include "Board.h"
#include "Coord.h"

class Game {
    Game() {}

    Board grid;
public:
    void action(Coord c1, Coord c2);
    void isValidAction(Coord c1, Coord c2);
    void deleteRow(Coord c1);
    void deleteColumn(Coord c1);
    void lDelete(Coord c1);
    void bomb(Coord c1);






};


#endif //CANDYCRUSH_GAME_H
