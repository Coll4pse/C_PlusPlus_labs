#ifndef NOUGHTS_AND_CROSSES_PLAYFIELD_H
#define NOUGHTS_AND_CROSSES_PLAYFIELD_H

#include <vector>

//
// Created by Михаил on 27.03.2020.
//

class PlayField {
public:
    class CellPos {
    public:
        CellPos() = delete;

        CellPos(int x, int y);

        int getX() const;
        int getY() const;

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

    CellStatus operator[](const CellPos pos) const;

    std::vector<CellPos> getEmptyCells() const;

    enum FieldStatus{
        fsInvalid,
        fsNormal,
        fsCrossesWin,
        fsNoughtsWin,
        fsDraw
    };

    FieldStatus checkFieldStatus() const;

    PlayField makeMove(const CellPos pos) const;

    PlayField() = default;

    CellStatus nextMove() const;

private:
    PlayField operator+(const CellPos pos) const;

    CellStatus cells[3][3] = {
            {csEmpty, csEmpty, csEmpty},
            {csEmpty, csEmpty, csEmpty},
            {csEmpty, csEmpty, csEmpty}
    };

    constexpr static int m_fieldDim = 3;
};

#endif //NOUGHTS_AND_CROSSES_PLAYFIELD_H
