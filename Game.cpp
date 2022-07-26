//
// Created by hars on 22/07/22.
//

#include <iostream>
#include <FL/Fl.H>
#include "Game.h"

void Game::draw() {
    board.draw();

    }


void Game::mouseClick(Coord mouseLoc) {
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            Cell &target = board.getCell(Coord{x, y});
            if (target.sq.contains(mouseLoc)) {
                //evalSelect(Coord {x,y});
                board.deleteCandy(target.cellCoord);
            }
        }
    }
}

void Game::evalSelect(Coord target){
    if(selection.x == -1){
        selection = target;
        return;
    }
    int absDistance = abs(selection.xDistanceTo(target) + selection.yDistanceTo(target));
    if(absDistance==1){
        evalMove(selection,target);
    }
    selection = Coord{-1,-1};
}

bool Game::validMove(Coord &target){
    std::vector <Coord> markedCandies;
    int targetType = board.getCandyType(target);
    //Scan right
    for (int x = 0; x < 8-target.x; ++x) {
        if(board.getCandyType(Coord{target.x+x,target.y})==targetType){
            markedCandies.emplace_back(target.x+x,target.y);
        }
        else {break;}
    }
    //scan left
    for (int x = 1; x < target.x+1; ++x) {
        if(board.getCandyType(Coord{target.x-x,target.y})==targetType){
            markedCandies.emplace_back(target.x-x,target.y);
        }
        else {break;}
    }
    //scan up
    for (int y = 1; y < target.y+1; ++y) {
        if(board.getCandyType(Coord{target.x,target.y-y})==targetType){
            markedCandies.emplace_back(target.x,target.y-y);
        }
        else {break;}
    }
    //scan down
    for (int y = 0; y < 8-target.y; ++y) {
        if(board.getCandyType(Coord{target.x,target.y+y})==targetType){
            markedCandies.emplace_back(target.x,target.y+y);
        }
        else {break;}
    }
    //delete marked candies
    for (Coord &c:markedCandies) {
        board.deleteCandy(c);
    }
    return markedCandies.empty();
}

bool Game::evalMove(Coord &c1, Coord &c2){
    board.swapCandy(c1,c2);
    if(!validMove(c2)){
        board.swapCandy(c2,c1);
        return false;
    }
    evalBoard();
    return true;
}

bool Game::evalBoard(){
//    board.swapCandy(c1,c2);
//    if(!searchAndDestroy()){
//        board.swapCandy(c2,c1);
//        return false;
//    }
    return true;
}


