//
// Created by Михаил on 27.03.2020.
//

#ifndef NOUGHTS_AND_CROSSES_PLAYFIELD_H
#define NOUGHTS_AND_CROSSES_PLAYFIELD_H

#include <cassert>
#include <vector>

class PlayField {
public:
    class CellPos {
    public:
        CellPos(int x, int y) {
            setX(x);
            setY(y);
        }

        int getX() { return  m_x;}
        void setX(int x) {
            assert(0 <= x && x <= 2);
            m_x = x;
        }

        int getY() { return  m_y;}
        void setY(int y)
        {
            assert(0 <= y && y <= 2);
            m_y = y;
        }

    private:
        CellPos() = default;

        int m_x, m_y;
    };

    PlayField();

    enum CellStatus
    {
        csEmpty,
        csCross,
        csNought
    };

    CellStatus operator[](CellPos *pos) const;

    std::vector<CellPos*> getEmptyCells() const;

    enum FieldStatus{
        fsInvalid,
        fsNormal,
        fsCrossesWin,
        fsNoughtsWin,
        fsDraw
    };

    FieldStatus checkFieldStatus() const;

    PlayField makeMove(CellPos *pos) const;

private:
    PlayField operator+( CellPos *pos) const;

    CellStatus cells[3][3];
};

#endif //NOUGHTS_AND_CROSSES_PLAYFIELD_H
