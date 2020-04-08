#ifndef NOUGHTS_AND_CROSSES_PLAYFIELD_H
#define NOUGHTS_AND_CROSSES_PLAYFIELD_H

#include <cassert>
#include <vector>

//
// Created by Михаил on 27.03.2020.
//

class PlayField {
public:
    class CellPos {
    public:
        CellPos() = delete;

        CellPos(int x, int y) {
            assert(x >= 0 && x <= 2 && y >= 0 && y <= 2);
            m_x = x;
            m_y = y;
        }

        int getX() const { return  m_x;}
        int getY() const { return  m_y;}

    private:
        int m_x = 0;
        int m_y = 0;
    };

    enum CellStatus
    {
        csEmpty,
        csCross,
        csNought
    };

    CellStatus operator[](CellPos pos) const;

    std::vector<CellPos> getEmptyCells() const;

    enum FieldStatus{
        fsInvalid,
        fsNormal,
        fsCrossesWin,
        fsNoughtsWin,
        fsDraw
    };

    FieldStatus checkFieldStatus() const;

    PlayField makeMove(CellPos pos) const;

    PlayField() = default;

    CellStatus nextMove() const;

private:
    PlayField operator+(CellPos pos) const;

    CellStatus cells[3][3] = {
            {csEmpty, csEmpty, csEmpty},
            {csEmpty, csEmpty, csEmpty},
            {csEmpty, csEmpty, csEmpty}
    };
};

#endif //NOUGHTS_AND_CROSSES_PLAYFIELD_H
