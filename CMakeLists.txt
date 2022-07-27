cmake_minimum_required(VERSION 3.22)
project(candycrush)

set(CMAKE_CXX_STANDARD 17)

add_executable(candycrush main.cpp MainWindow.cpp MainWindow.h Game.cpp Game.h Board.cpp Board.h Coord.h Cell.cpp Cell.h Candy.cpp Candy.h ConstantsCC.h Square.h Square.cpp CandyRNG.h Animations.cpp Animations.h)
