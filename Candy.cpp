//
// Created by hars on 23/07/22.
//

#include <iostream>
#include "Candy.h"


Candy::Candy(Coord location) {
    candyType = candyRNG::drawType(6);
    center.x = location.x-(windowWidth/10)*0.3125;
    center.y = location.y-(windowHeight/10)*0.3125;
    calculateColor();

}
Candy::Candy(int type, Coord location) {
    candyType = type;
}


void Candy::calculateColor() {
    switch (candyType) {
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
            break;

    };
}

void Candy::draw(){
    if(candyType==-1){
        return;
    }
    fl_color(candyColor);
    //std::cout << center.x << center.y << std::endl;
    fl_pie(center.x,center.y,radius,radius,0,360);
}

int Candy::getCandyType() const {
    return candyType;
}

void Candy::setCandyType(int candyType) {
    Candy::candyType = candyType;
    calculateColor();
}






