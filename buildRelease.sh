#!/bin/bash

clear

warnings=""
#warnings="-Wall -Wextra -Wpedantic"
#warnings="${warnings} -Weffc++"

releaseArgs=""

g++ -std=c++17 $warnings $releaseArgs *.cpp -o b.out -lfltk

