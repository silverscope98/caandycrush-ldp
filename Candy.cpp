//
// Created by hars on 23/07/22.
//

#include "Candy.h"


Candy::Candy(Point centerPoint) {
    shuffleType();
    center = centerPoint;
    transformToType();

}

void Candy::shuffleType() {
    setCandyType(CandyRNG::drawType(emptyBlackList));

}

void Candy::transformToType() {
    resetLength();
    switch (candyType) {
        case 0:
            candyColor = FL_WHITE;
            break;
        case 1:
            candyColor = FL_RED;
            break;
        case 2:
            candyColor = FL_DARK_YELLOW;
            break;
        case 3:
            candyColor = FL_GREEN;
            break;
        case 4:
            candyColor = FL_BLUE;
            break;
        case 5:
            candyColor = FL_CYAN;
            break;
        case 6:
            candyColor = FL_MAGENTA;
            break;
        case 7:
            candyColor = FL_GRAY0;
            break;
        case 8:
            candyColor = FL_BLACK;
            break;
        case 9:
            candyColor = FL_WHITE;
            length = 2;
            break;

    };
}

void Candy::draw(){
    fl_color(candyColor);
    fl_polygon	(center.x,center.y+length/2,
                   center.x-length/2,center.y,
                   center.x,center.y-length/2,
                   center.x+length/2,center.y);
}


void Candy::setCandyType(int candyType) {

    Candy::candyType = candyType;
    transformToType();
}

void Candy::resetLength() {
    length= defaultCandyLength;
}








