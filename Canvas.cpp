//
// Created by hars on 22/07/22.
//

#include <iostream>
#include "Canvas.h"

void Canvas::draw() {
    grid.draw();

    }

Canvas::Canvas() {
    grid = Board();
    grid.deleteCandy(Coord{1,2});
    grid.swapCandy(Coord{1,2},Coord{1,1});
}

