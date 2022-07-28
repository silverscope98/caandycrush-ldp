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
    Animations animations{board};
public:
    Coord selection{-1, -1};
    Game() = default;
    void draw();
    void mouseClick(Coord mouseLoc);

    void evalSelect(Coord target);

    bool streakCutter(Coord &core, bool evaluatingBoard);

    bool evalBoard();


    //void deleteCandy(Coord target);
    void multiDeleteCandies(std::vector <Coord> &markedCandies, bool evaluatingBoard);

    void printDetails(Coord c1);

    bool evalMove(Coord &c1, Coord &c2);

    void swapCandy(Coord c1, Coord c2, int speed=2);

    void sinkCandy(int x);

    void rainCandy(int x);
};


#endif //CANDYCRUSH_GAME_H
