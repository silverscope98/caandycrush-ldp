//
// Created by hars on 23/07/22.
//
#include <FL/fl_draw.H>
#include "Square.h"

Square::Square(Coord center,int l, Fl_Color fillColor,Fl_Color frameColor)
               :center(center),l(l),fillColor(fillColor),frameColor(frameColor){}



void Square::draw() {
    fl_draw_box(FL_FLAT_BOX,center.x-l/2,center.y-l/2,l,l,fillColor);
    fl_draw_box(FL_BORDER_FRAME,center.x-l/2,center.y-l/2,l,l,frameColor);
}

void Square::setFillColor(Fl_Color newFillColor) {
    fillColor = newFillColor;

}

void Square::setFrameColor(Fl_Color newFrameColor) {
    frameColor=newFrameColor;

}

bool Square::contains(Coord p) {
    return p.x>=center.x-l/2 &&
           p.x<center.x+l/2 &&
           p.y>=center.y-l/2 &&
           p.y<center.y+l/2;
}

Square::Square(Coord centerPoint) {
    l = cellSize;
    center = centerPoint;
}


