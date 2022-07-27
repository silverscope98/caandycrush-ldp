//#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Box.H>

#include "MainWindow.h"
/*OUTLINE:
 * 6 HOURS SET 1+2
 * ANIMATE SWAP
 * ANIMATE FALL
 * IMPLEMENT IF SWAP IS VALID
 * ->WHILE(true)
    * IF SCAN == FALSE ; BREAK
    * GENERATE CANDIES BY ROW
 * ELSE SWAP BACK
 *
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
 * 4 HOURS
 * ADD ICING
 * ADD WALLS
    * ADD WALL MECHANIC
 */


int main(int argc, char** argv){
    srand(0);
    MainWindow mw;
    mw.show();
    return Fl::run();
}