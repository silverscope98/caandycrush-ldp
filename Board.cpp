//
// Created by hars on 23/07/22.
//

#include <stdexcept>
#include <iostream>
#include "Board.h"


Board::Board() {
    for (int i = 0; i <9 ; ++i) {
        for (int j = 0; j < 9; ++j) {
            boardCells[i][j] = Cell{i, j};
        }
    }

    //Horizontal cleanup
    for (int y = 0; y <9 ; ++y){
        int previousType = 0;
        int counter = 0;
        for (int x = 0; x < 9; ++x) {
            if (previousType == getCandyType(Coord{x, y})) {
                if (++counter == 2) {
                    generateDisjointCandy(Coord{x, y});
                }
            }
            else{
                counter = 0;
            }
            previousType = getCandyType(Coord{x, y});
        }
    }

    //Vertical cleanup
    for (int x = 0; x <9 ; ++x){
        int previousType = 0;
        int counter = 0;
        for (int y = 0; y < 9; ++y) {
            if (previousType == getCandyType(Coord{x, y})) {
                if (++counter == 2) {
                    generateDisjointCandy(Coord{x, y});
                }
            }
            else{
                counter = 0;
            }
            previousType = getCandyType(Coord{x, y});
        }
    }
}

Cell& Board::getCell(Coord target) {
    return boardCells[target.x][target.y];
}

Candy& Board::getCandy(Coord target) {
    return getCell(target).candy;
}
int Board::getCandyType(Coord target) {
    return getCandy(target).candyType;
}
void Board::setCandyType(Coord target, int candyType) {
    getCandy(target).setCandyType(candyType);
}

void Board::deleteCandy(Coord target) {
    Candy &targetCandy = getCandy(target);
    Animations::shrinkCandy(targetCandy);
    targetCandy.resetLength();
    sinkCandy(target);
    Animations::growCandy(getCandy(Coord{target.x,0}));
}

void Board::sinkCandy(Coord target) {
    if(getCandyType(target) != 0){
        throw std::invalid_argument( "Square has not been deleted" );
    };
    int x = target.x;
    int y = target.y - 1;
    while(y>=0) {
        swapCandy(Coord{x, y + 1}, Coord{x, y});
        y -= 1;
    }
}

void Board::swapCandy(Coord c1, Coord c2) {
    int c1type = getCandyType(c1);
    int c2type = getCandyType(c2);
    setCandyType(c1,c2type);
    setCandyType(c2,c1type);
}

std::vector<Coord> Board::cellsOnPath(int range, Coord target, int xDir, int yDir) {
    std::vector<Coord> output;
    int x = target.x + xDir;
    int y = target.y + yDir;

    for (int i = 0; i < range; ++i) {
        while (y>=0 && y<=9 && x>=0 && x<=9){
            output.emplace_back(x,y);
            y+=yDir;
            x+=xDir;
        }
    }
    return output;
}


std::vector<Coord> Board::getAboveCells(int range, Coord target) {
    return cellsOnPath(range, target, 0, -1);
}


std::vector<Coord> Board::getBelowCells(int range, Coord target) {
    return cellsOnPath(range, target, 0, +1);

}

std::vector<Coord> Board::getLeftCells(int range, Coord target) {
    return cellsOnPath(range, target, -1, 0);
}

std::vector<Coord> Board::getRightCells(int range, Coord target) {
    return cellsOnPath(range, target, +1, 0);
}

void Board::generateDisjointCandy(Coord c1) {
    std::vector <int> neighborTypes;
    if(c1.x!=0) {
        neighborTypes.push_back(getCandyType(getLeftCells(1,c1)[0]));
    }
    if(c1.x!=8) {
        neighborTypes.push_back(getCandyType(getRightCells(1,c1)[0]));
    }
    if(c1.y!=0){
        neighborTypes.push_back(getCandyType(getAboveCells(1,c1)[0]));
    }
    if(c1.y!=8){
        neighborTypes.push_back(getCandyType(getBelowCells(1,c1)[0]));
    }
    setCandyType(c1, CandyRNG::drawType(neighborTypes));
}



void Board::draw() {
    for (int i = 0; i <9 ; ++i) {
        for (int j = 0; j < 9; ++j) {
            boardCells[i][j].draw();
        }
    }
}


/*
bool Board::actionExists() {
    return false;
}
 */
