//
// Created by hars on 22/07/22.
//

#include "Canvas.h"

void Canvas::draw() {
    grid->draw();
    }

Canvas::Canvas() {
    grid = new Board();
}

