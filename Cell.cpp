//
// Created by hars on 23/07/22.
//

#include "Cell.h"
#include "ConstantsCC.h"


Cell::Cell(int x, int y) {
    int sqLength = (windowWidth+windowHeight)/20;
    int candyType = 1;
    cellCoord = Coord{x,y};
    pixelPoint = Coord{7+(x+1)*sqLength,20+(y+1)*sqLength};

    candy = Candy{pixelPoint};
    sq =  Square{pixelPoint, sqLength, FL_WHITE, FL_BLACK,};
}

void Cell::draw() {
    sq.draw();
    candy.draw();

}


