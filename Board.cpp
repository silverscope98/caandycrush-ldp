//
// Created by hars on 23/07/22.
//

#include <stdexcept>
#include <iostream>
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
            boardCells[i][j]->draw();
        }
    }
}

void Board::generateCandy(Coord c1) {


}

void Board::deleteCandy(Coord c1) {
    boardCells[c1.x][c1.y]->candy.candyType = -1;
}
/*
void Board::sinkCandy(Coord deletedCell) {
    if(boardCells[deletedCell.x][deletedCell.y] != nullptr){
        throw std::invalid_argument( "Square has not been deleted" );
    };
    int y = deletedCell.y -1;
    while(y>=0){



    }

}/*/

bool Board::swapCandy(Coord c1, Coord c2) {
    int c1type = boardCells[c1.x][c1.y]->candy.candyType;
    int c2type = boardCells[c2.x][c2.y]->candy.candyType;
    boardCells[c1.x][c1.y]->candy.candyType = c2type;
    boardCells[c2.x][c2.y]->candy.candyType = c1type;


}


/*
bool Board::actionExists() {
    return false;
}
 */
