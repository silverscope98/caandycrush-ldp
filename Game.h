//
// Created by hars on 22/07/22.
//

#ifndef CANDYCRUSH_GAME_H
#define CANDYCRUSH_GAME_H
#include <vector>
#include <unistd.h>
#include "Board.h"
#include "Animations.h"

#include <cmath>

class Game{
    Board board;
public:
    Coord selection{-1, -1};
    Game() = default;
    void draw();
    void mouseClick(Coord mouseLoc);
//    void keyPressed(int keyCode) {exit(0);}
//    void action(Coord c1, Coord c2);
//    void isValidAction(Coord c1, Coord c2);
//    void deleteRow(Coord c1);
//    void deleteColumn(Coord c1);
//    void lDelete(Coord c1);
//    void bomb(Coord c1);
    void evalSelect(Coord target);

    bool evalMove(Coord &c1, Coord &c2);

    bool validMove(Coord &target);

    bool evalBoard();
};


#endif //CANDYCRUSH_GAME_H
