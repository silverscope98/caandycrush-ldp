//
// Created by hars on 22/07/22.
//

#ifndef CANDYCRUSH_CANVAS_H
#define CANDYCRUSH_CANVAS_H
#include <vector>
#include <unistd.h>
#include "Board.h"
//#include <Game.h>

#include <cmath>

class Canvas{
    Board grid;
    //Game game;
public:
    Canvas();
    void draw();


    //void mouseMove(Point mouseLoc);
    //void mouseClick(Point mouseLoc);
    void keyPressed(int keyCode) {exit(0);}
};


#endif //CANDYCRUSH_CANVAS_H
