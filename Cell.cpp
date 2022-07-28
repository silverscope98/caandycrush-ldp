//
// Created by hars on 23/07/22.
//

#include "Cell.h"


Cell::Cell(int x, int y) {
    int candyType = 1;
    cellCoord = Coord{x,y};
    centerPxl = Point{static_cast<float>(7 + (x + 1) * cellSize), static_cast<float>(20 + (y + 1) * cellSize)};

    candy = Candy{centerPxl};
    sq =  Square{centerPxl};
}

void Cell::draw() {
    sq.draw();
    candy.draw();

}




