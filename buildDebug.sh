#!/bin/bash

clear

warnings="-Wall -Wextra -Wpedantic"
#warnings="${warnings} -Weffc++"

debugArgs="-fsanitize=address -g3 -Og -O0"

g++ -std=c++17 $warnings $debugArgs *.cpp -o a.out -lfltk

