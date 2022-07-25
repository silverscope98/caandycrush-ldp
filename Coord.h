//
// Created by hars on 23/07/22.
//

#ifndef CANDYCRUSH_COORD_H
#define CANDYCRUSH_COORD_H


class Coord {
public:
    Coord(int x, int y) : x(x), y(y) {}

    Coord() = default;

    int x;
    int y;

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

};





#endif //CANDYCRUSH_COORD_H
