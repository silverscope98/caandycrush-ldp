//
// Created by hars on 26/07/22.
//

#include <FL/Fl.H>
#include "Animations.h"

[[maybe_unused]] void Animations::shrinkCandy(Coord target) {
    std::vector<Coord> T;
    T.push_back(target);
    shrinkCandies(T);
}
void Animations::shrinkCandies(std::vector<Coord> &targets) {
    int l = defaultCandyLength;
    while (l>=defaultCandyLength*0.05) {
        l *=0.8;
        for (Coord &c: targets) {
            board.getCandy(c).length= l;
            board.getCandy(c).draw();
            Fl::wait(1);
        }
    }
    for (Coord &c: targets) {
        board.setCandyType(c,0);
    }
}

void Animations::translateCandy(Cell &target,Coord endPoint) {
    int &l = target.candy.length;
    Coord endCenter = endPoint.getCenterPixel();
    while(l>=0.05){
        l = l*0.95;
        target.draw();
        Fl::wait(1);
    }
}

Animations::Animations(Board &board) : board(board) {}


