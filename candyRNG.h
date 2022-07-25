//
// Created by hars on 24/07/22.
//

#include <vector>
#include <random>

#ifndef CANDYCRUSH_RNG_H
#define CANDYCRUSH_RNG_H

#endif //CANDYCRUSH_RNG_H


class candyRNG{
public:
    static int drawType(int n, int eliminateType=0){
        std::vector<int> hat;
        makeHat(n,hat,eliminateType);
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, n-1);
        return hat[distrib(gen)];
    }
    ;
    static void makeHat(int n,std::vector<int> &hat, int eliminateInt){
        for (int i = 1; i < n+1; ++i) {
            if(i==eliminateInt) continue;
            hat.push_back(i);
        }
    };


};