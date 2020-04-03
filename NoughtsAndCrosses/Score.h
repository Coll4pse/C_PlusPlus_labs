#ifndef NOUGHTS_AND_CROSSES_SCORE_H
#define NOUGHTS_AND_CROSSES_SCORE_H

#endif //NOUGHTS_AND_CROSSES_SCORE_H

#include <cassert>

//
// Created by Михаил on 03.04.2020.
//

struct Score{
    int operator[](int index){
        switch (index){
            case 0:
                return CrossesWin;
            case 1:
                return NoughtsWin;
            case 2:
                return Draws;
            default:
                assert(false);
        }
    }

    int CrossesWin = 0;
    int NoughtsWin = 0;
    int Draws = 0;
};