//
// Created by hars on 26/07/22.
//

#include <FL/Fl.H>
#include "Animations.h"

[[maybe_unused]] void Animations::shrinkCandy(Coord target) {
    std::vector<Coord> T;
    T.push_back(target);
    shrinkCandies(T);
}
void Animations::shrinkCandies(std::vector<Coord> &targets) {
    int l = defaultCandyLength;
    while (l>=defaultCandyLength*0.05) {
        l *=0.75;
        for (Coord &c: targets) {
            board.getCandy(c).length= l;
            board.getCandy(c).draw();
            Fl::wait(0.5);
        }
    }
    for (Coord &c: targets) {
        board.setCandyType(c,0);
    }
}

void Animations::intersectCandy(Coord c1, Coord c2, int speedMultiplier) {
    //add warning for invalid c1,c2 (ie: abs distance is more than 1
    Candy &candy1 = board.getCandy(c1);
    Candy &candy2 = board.getCandy(c2);
    Point intersection = Point{candy1.center.x+c1.xDistanceTo(c2)*cellSize/2,
                               candy1.center.y+c1.yDistanceTo(c2)*cellSize/2};
    std::cout <<"INT : ";

    intersection.printPoint();
    std::cout << std::endl;

    while(true){
        candy1.center.printPoint();
        std::cout << std::endl;
        if(abs(candy1.center.xDistanceTo(candy2.center))<=speedMultiplier*1.5 && abs(candy1.center.yDistanceTo(candy2.center))<=speedMultiplier*1.5 ){
            candy1.center = intersection;
            candy2.center = intersection;
            break;
        }
        if(c1.x!=c2.x){
        candy1.center.x += speedMultiplier*c1.xDistanceTo(c2);
        candy2.center.x += speedMultiplier*c2.xDistanceTo(c1);
        }
        else{
            candy1.center.y += speedMultiplier*c1.yDistanceTo(c2);
            candy2.center.y += speedMultiplier*c2.yDistanceTo(c1);
        }
        candy1.draw();
        candy2.draw();
        Fl::wait(0.1);
    }
}
void Animations::restoreCandy(Coord c1, Coord c2, int speedMultiplier) {
    Candy &candy1 = board.getCandy(c1);
    Candy &candy2 = board.getCandy(c2);
    while(true){
        Point cell1_Center = board.getCell(c1).centerPxl;
        Point cell2_Center = board.getCell(c2).centerPxl;

        if(abs(candy1.center.xDistanceTo(cell1_Center))<=speedMultiplier*1.5 && abs(candy1.center.yDistanceTo(cell1_Center))<=speedMultiplier*1.5 ){
            candy1.center = cell1_Center;
            candy2.center = cell2_Center;
            break;
        }
        if(c1.x!=c2.x){
            candy1.center.x += speedMultiplier*c2.xDistanceTo(c1);
            candy2.center.x += speedMultiplier*c1.xDistanceTo(c2);
        }
        else{
            candy1.center.y += speedMultiplier*c2.yDistanceTo(c1);
            candy2.center.y += speedMultiplier*c1.yDistanceTo(c2);
        }
        candy1.draw();
        candy2.draw();
        Fl::wait(0.1);

    }
}


Animations::Animations(Board &board) : board(board) {}


