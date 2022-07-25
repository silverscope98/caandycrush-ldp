//
// Created by hars on 23/07/22.
//

#include "Board.h"

Board::Board() {
    for (int i = 0; i <9 ; ++i) {
        for (int j = 0; j < 9; ++j) {
            boardCells[i][j] = new Cell(i, j);
        }
    }
}

void Board::draw() {
    for (int i = 0; i <9 ; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(boardCells[i][j] == nullptr) continue;
            boardCells[i][j]->draw();
        }
    }
}

void Board::generateCandy(Coord c1) {


}

void Board::deleteCandy(Coord c1) {
    delete boardCells[c1.x][c1.y];
}


/*
bool Board::actionExists() {
    return false;
}
 */
