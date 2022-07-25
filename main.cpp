//#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Box.H>

#include "MainWindow.h"
/*OUTLINE:
 * DRAW CANDIES FOR EACH CELL
 * IMPLEMENT MOUSECLICK
 * REMOVE/ADD/SWAP CANDIES
 * IMPLEMENT SHIFT DOWN + STRIKE
 */


int main(int argc, char** argv){
    srand(0);
    MainWindow mw;
    mw.show();
    return Fl::run();
}