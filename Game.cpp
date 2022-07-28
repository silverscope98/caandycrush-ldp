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
                evalSelect(Coord {x,y});
            }
        }
    }
}

void Game::printDetails(Coord c1){
    std::cout << "CANDY TYPE :" << board.getCandyType(c1) << std::endl
              << "COORD :";
    c1.printCoord();
    std::cout << "COORD :";
    board.getCell(c1).centerPxl.printPoint();
    std::cout << std::endl;
    std::cout << std::endl;


}

void Game::evalSelect(Coord target){
    if(selection.x == -1){
        selection = target;
        std::cout << "Selected : " << std::endl;
        printDetails(selection);
        return;
    }
    int absDistance = abs(selection.xDistanceTo(target) + selection.yDistanceTo(target));
    if(absDistance==1){
        evalMove(selection,target);
    }
    selection = Coord{-1,-1};
}

bool Game::streakCutter(Coord &core,bool evaluatingBoard = false){
    std::vector <Coord> markedCandies;
    std::vector <Coord> tempMarked;
    int coreType = board.getCandyType(core);

    //Horizontal scan
        //scan right
    for (int x = 1; x < 9 - core.x; ++x) {
        if(board.getCandyType(Coord{core.x + x, core.y}) == coreType){
            tempMarked.emplace_back(core.x + x, core.y);
        }
        else break;
    }
        //scan left
    for (int x = 1; x < core.x + 1; ++x) {
        bool targetMatches = board.getCandyType(Coord{core.x - x, core.y}) == coreType;
        if (targetMatches) {
            tempMarked.emplace_back(core.x - x, core.y);
        }
        else break;
    }
    if(tempMarked.size()>=2){
        markedCandies.insert(markedCandies.end(), tempMarked.begin(), tempMarked.end());
    }
    tempMarked.clear();
    //Vertical Scan
        //scan up
    for (int y = 1; y < core.y + 1; ++y) {
        if(board.getCandyType(Coord{core.x, core.y - y}) == coreType){
            tempMarked.emplace_back(core.x, core.y - y);
        }
        else break;
    }
        //scan down
    for (int y = 1; y < 9 - core.y; ++y) {
        bool targetMatches = board.getCandyType(Coord{core.x, core.y + y}) == coreType;
        if(targetMatches){
            tempMarked.emplace_back(core.x, core.y + y);
        }
        else break;
    }
    if(tempMarked.size()>=2){
        markedCandies.insert(markedCandies.end(), tempMarked.begin(), tempMarked.end());
    }
    tempMarked.clear();

    //delete marked candies
    if(!markedCandies.empty()){
        markedCandies.push_back(core);
        multiDeleteCandies(markedCandies,evaluatingBoard);
        return true;
    }
    return false;
}

bool Game::evalMove(Coord &c1, Coord &c2){
    printDetails(c2);
    swapCandy(c1, c2);
    if(!streakCutter(c2)){
        swapCandy(c2, c1);
        return false;
    }
    evalBoard();
    return true;
}

bool Game::evalBoard(){
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            Coord core = Coord{x, y};
            if (streakCutter(core, true)) {
                return false;
            }
        }
    }
    return true;
}


void Game::multiDeleteCandies(std::vector <Coord> &markedCandies, bool evaluatingBoard = false) {

    animations.shrinkCandies(markedCandies);

    for (Coord &c:markedCandies) {
        board.getCandy(c).resetLength();
    }

    std::vector <int> columnsToUpdate;
    for (Coord &c:markedCandies) {
        columnsToUpdate.push_back(c.x);
    }
    std::sort(columnsToUpdate.begin(), columnsToUpdate.end());
    for (int &column:columnsToUpdate){
        sinkCandy(column);
        rainCandy(column);
    }

    while(true){
        if(evalBoard()) break;
    }
    for (int x = 0; x < 9; ++x) {
        rainCandy(x);
    }
}

void Game::swapCandy(Coord c1, Coord c2,int speed) {
    animations.intersectCandy(c1,c2,speed);
    board.switchCandyType(c1,c2);
    animations.restoreCandy(c1,c2,speed);
}


void Game::sinkCandy(int x) {
    if(board.getCandyType(Coord{x,0})==0){
        return;
    }
    int candyCount = 0;
    for (int y = 0; y < 9; ++y) {
        if(y==8 || board.getCandyType(Coord{x,y+1})!=0) {
            candyCount+=1;
            continue;
        }
        else{
            swapCandy(Coord{x, y}, Coord{x, y + 1},22);
        }
    }
    if(candyCount==9) {
        return;
    }
    sinkCandy(x);
}


void Game::rainCandy(int x){
    if(board.getCandyType(Coord{x,0})!=0){
        return;
    }
    board.getCandy(Coord{x,0}).shuffleType();
    sinkCandy(x);
}
