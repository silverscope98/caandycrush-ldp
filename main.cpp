//#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Box.H>

#include "MainWindow.h"
/*OUTLINE:
 * 2 HOURS SET 1+2
 * ANIMATE SWAP
 * ANIMATE FALL
 *
 * 3 HOURS SET 3
 * RESET IF NO MORE MOVES LEFT
 * ADD SCORE COUNTER
 * ADD BEST SCORE COUNTER
 * LOADING SCREEN
 * ADD SUGGESTIONS
 *
 * 4 HOURS
 * ADD FXNALITY FOR SPECIAL CANDY
 * SLIDING ANIMATION TO SWAP
 *

 *
 * 4 HOURS
 * ADD ICING
 * ADD WALLS
    * ADD WALL MECHANIC
 * 4 HOURS CLEANUP
 * Make coord/point be template class;
 * Make coord to point converter
 * Add restrictions to functions where needed
 * To Remove redundancy from fxns of board.disjointcandy
 * Remove redundancy from intersect/restore candy
 * Commentate
 */


int main(int argc, char** argv){
    srand(0);
    MainWindow mw;
    mw.show();
    return Fl::run();
}