#include "PlayField.h"
#include <cassert>

PlayField::CellStatus PlayField::operator[](const CellPos pos) const {
    return cells[pos.getX()][pos.getY()];
}

PlayField PlayField::operator+(const PlayField::CellPos pos) const {
    assert((*this)[pos] == csEmpty);
    PlayField newField(*this);
    newField.cells[pos.getX()][pos.getY()] = nextMove();
    return newField;
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    auto result = std::vector<PlayField::CellPos>();
    for (int i = 0; i < m_fieldDim; i++)
        for (int j = 0; j < m_fieldDim; j++)
            if (cells[i][j] == csEmpty)
                result.emplace_back(i, j);
    return result;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    int crossCount = 0, noughtCount = 0;
    bool isCrossWin = false, isNoughtWin = false;

    for (int i = 0; i < m_fieldDim; i++) {
        int crossCountInRow = 0, crossCountInCol = 0, noughtCountInRow = 0, noughtCountInCol = 0;

        for (int j = 0; j < m_fieldDim; j++) {
            switch (cells[i][j]){
                case csCross:
                    crossCount++;
                    crossCountInRow++;
                    break;
                case csNought:
                    noughtCount++;
                    noughtCountInRow++;
                    break;
            }
            switch (cells[j][i])
            {
                case csCross:
                    crossCountInCol++;
                    break;
                case csNought:
                    noughtCountInCol++;
                    break;
            }
        }

        if (crossCountInCol == 3 || crossCountInRow == 3)
            isCrossWin = true;

        if (noughtCountInCol == 3 || noughtCountInRow == 3)
            isNoughtWin = true;
    }

    if (cells[1][1] != csEmpty && ((cells[0][0] == cells[1][1] && cells[1][1] == cells[2][2])  ||
    (cells[0][2] == cells[1][1] && cells[1][1] == cells[2][0])))
        cells[1][1] == csCross ? isCrossWin = true : isNoughtWin = true;

    if (isCrossWin && isNoughtWin)
        return fsInvalid;
    else if (isCrossWin)
        return fsCrossesWin;
    else if(isNoughtWin)
        return fsNoughtsWin;
    else if(crossCount + noughtCount == 9)
        return fsDraw;
    else
        return fsNormal;
}

PlayField PlayField::makeMove(const PlayField::CellPos pos) const {
    FieldStatus status = checkFieldStatus();
    assert((status != fsInvalid && status != fsNoughtsWin && status != fsCrossesWin && status != fsDraw)
        || (*this)[pos] == csEmpty);
    return (*this) + pos;
}

PlayField::CellStatus PlayField::nextMove() const {
    FieldStatus status = checkFieldStatus();
    assert(status != fsInvalid && status != fsNoughtsWin && status != fsCrossesWin && status != fsDraw);

    int crossesCount = 0, noughtsCount = 0;

    for (int i = 0; i < m_fieldDim; i++)
        for (int j = 0; j < m_fieldDim; j++) {
            if (cells[i][j] == csCross)
                crossesCount++;
            else if (cells[i][j] == csNought)
                noughtsCount++;
        }

    return (crossesCount - noughtsCount == 0 ? csCross : csNought);
}

PlayField::CellPos::CellPos(int x, int y)  {
    assert(x >= 0 && x <= 2 && y >= 0 && y <= 2);
    m_x = x;
    m_y = y;
}

int PlayField::CellPos::getX() const  { return  m_x; }

int PlayField::CellPos::getY() const { return m_y; }