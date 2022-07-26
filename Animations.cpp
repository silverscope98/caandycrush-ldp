//
// Created by hars on 26/07/22.
//

#include <FL/Fl.H>
#include "Animations.h"

void Animations::shrinkCandy(Candy &target) {
    int &l = target.length;
    while(l>=defaultCandyLength*0.05) {
        l = l*0.95;
        target.draw();
        Fl::wait(1);
    }

    target.setCandyType(0);
}
void Animations::growCandy(Candy &target) {
    int &l = target.length;
    l = 5;
    target.shuffleType();
    while (l <= defaultCandyLength) {
        l = l * 1.2;
        if(l >= defaultCandyLength*0.9){
            break;
        }
        target.draw();
        Fl::wait(5);
    }
    target.resetLength();

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