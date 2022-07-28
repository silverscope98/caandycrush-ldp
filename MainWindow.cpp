//
// Created by hars on 22/07/22.
//

#include "MainWindow.h"


int MainWindow::isLoading = 0;

void MainWindow::drawLoadingScreen(){
    fl_font(FL_HELVETICA,18);
    fl_color(FL_BLACK);
    fl_draw("Harsh and Omar's LDP2 Project",windowWidth/3,windowHeight/2);
    fl_draw("Rhombus crush 1.0",windowWidth/2.5,windowHeight/2.5);
    isLoading-=1;

}
void MainWindow::drawScore() {
    fl_font(FL_HELVETICA,18);
    fl_color(FL_BLACK);
    //draw score
    fl_draw("Score : ", windowWidth*0.05, windowHeight*0.05);
    fl_draw(std::to_string(game.score).c_str(), windowWidth*.15, windowHeight*0.05);
    //draw best score
    fl_draw("Best Score : ", windowWidth*0.65, windowHeight*0.05);
    fl_draw(std::to_string(game.bestScore).c_str(), windowWidth*.8, windowHeight*0.05);

}

MainWindow::MainWindow() : Fl_Window(100, 100,
                                    windowWidth, windowHeight,
                                    "Candy Crush") {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);
}

void MainWindow::draw() {
    //std::cout<< isLoading;
    Fl_Window::draw();
    if(isLoading)drawLoadingScreen();
    else {
        drawScore();
        game.draw();
    }

}

int MainWindow::handle(int event) {
    switch (event) {
//        case FL_MOVE:
//            game.mouseMove(Coord{Fl::event_x(), Fl::event_y()});
//            return 1;
        case FL_PUSH:
            game.mouseClick(Coord{Fl::event_x(), Fl::event_y()});
            return 1;
    }
    return 0;
}


void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    float fq = 1/ refreshPerSecond;
    float t = isLoading * 3 + fq;
    Fl::repeat_timeout(t, Timer_CB, userdata);}
    //Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);}
    //Fl::repeat_timeout(0.5, Timer_CB, userdata);}





