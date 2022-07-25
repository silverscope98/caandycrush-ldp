//
// Created by hars on 22/07/22.
//

#ifndef CANDYCRUSH_MAINWINDOW_H
#define CANDYCRUSH_MAINWINDOW_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <iostream>
#include <random>
#include "Canvas.h"
#include "ConstantsCC.h"
using namespace std;

class MainWindow : public Fl_Window{


    Canvas canvas;
    public:

    MainWindow();

        void draw() override;

        int handle(int event) override;

        static void Timer_CB(void *userdata);

    };


#endif //CANDYCRUSH_MAINWINDOW_H
