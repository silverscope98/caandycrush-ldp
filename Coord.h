//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_COORD_H
#define CANDYCRUSH_COORD_H


#include <vector>
#include <iostream>
#include "ConstantsCC.h"

class Point {
public:
    float x;
    float y;
    Point(float x, float y) : x(x), y(y) {
    }
    float xDistanceTo(Point c2){
        return c2.x-x;
    }
    float yDistanceTo(Point c2){
        return c2.y-y;
    }
    Point() = default;
    void printPoint(){
        std::cout << "{" <<x << ", "<< y << "}" ;
    }
};


class Coord {
public:
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {
    }
    Coord() = default;

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
