//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_COORD_H
#define CANDYCRUSH_COORD_H


#include <vector>
#include <iostream>
#include "ConstantsCC.h"

class Coord {
public:
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {
    }
    Coord() = default;
    Coord getCenterPixel() const{
        return Coord{7+(x+1)*cellSize,20+(y+1)*cellSize};
    };
    int xDistanceTo(Coord c2){
        return c2.x-x;
    }
    int yDistanceTo(Coord c2){
        return c2.y-y;
    }
    void printCoord(){
        std::cout << "{" <<x << ", "<< y << "}" ;
    }


};





#endif //CANDYCRUSH_COORD_H
