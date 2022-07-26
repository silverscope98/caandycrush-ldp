//
// Created by hars on 23/07/22.
//

#include "Cell.h"


Cell::Cell(int x, int y) {
    int candyType = 1;
    cellCoord = Coord{x,y};
    candy = Candy{Coord{x,y}};
    sq =  Square{cellCoord.getCenterPixel()};
}

void Cell::draw() {
    sq.draw();
    candy.draw();

}




