//
// Created by hars on 24/07/22.
//

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#ifndef CANDYCRUSH_RNG_H
#define CANDYCRUSH_RNG_H

#endif //CANDYCRUSH_RNG_H


class CandyRNG{
public:
    static int drawType(std::vector<int> &blackList,int n=6){
        std::vector<int> hat;
        makeHat(n,hat,blackList);
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, hat.size()-1);
        int c = distrib(gen);
        return hat[c];
    }
    ;
    static void makeHat(int n,std::vector<int> &hat, std::vector<int>& blackList){
        for (int i = 1; i < n+1; ++i) {
            if(std::find(blackList.begin(), blackList.end(), i) != blackList.end()){
            continue;}
            hat.push_back(i);
        }
    };


};