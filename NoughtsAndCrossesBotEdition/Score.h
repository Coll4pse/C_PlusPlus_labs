#ifndef NOUGHTS_AND_CROSSES_SCORE_H
#define NOUGHTS_AND_CROSSES_SCORE_H

#endif //NOUGHTS_AND_CROSSES_SCORE_H

struct Score{
    void operator+(const Score otherScore) {
        CrossesWin += otherScore.CrossesWin;
        NoughtsWin += otherScore.NoughtsWin;
        Draws += otherScore.Draws;
    }

    int CrossesWin = 0;
    int NoughtsWin = 0;
    int Draws = 0;
};