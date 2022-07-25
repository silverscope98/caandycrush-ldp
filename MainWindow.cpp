//
// Created by hars on 22/07/22.
//

#include "MainWindow.h"



MainWindow::MainWindow() : Fl_Window(100, 100,
                                    windowWidth, windowHeight,
                                    "Candy Crush") {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);}

void MainWindow::draw() {
    Fl_Window::draw();
    this->canvas.draw();

}

int MainWindow::handle(int event) {return 0;}


void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);}






