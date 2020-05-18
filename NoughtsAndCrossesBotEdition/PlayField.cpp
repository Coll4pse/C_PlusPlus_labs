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
    for (int i = 0; i < fieldDim; i++)
        for (int j = 0; j < fieldDim; j++)
            if (cells[i][j] == csEmpty)
                result.emplace_back(i, j);
    return result;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    int crossCount = 0, noughtCount = 0;
    bool isCrossWin = false, isNoughtWin = false;

    for (int i = 0; i < fieldDim; i++) {
        int crossCountInRow = 0, crossCountInCol = 0, noughtCountInRow = 0, noughtCountInCol = 0;

        for (int j = 0; j < fieldDim; j++) {
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

        if (crossCountInCol == fieldDim || crossCountInRow == fieldDim)
            isCrossWin = true;

        if (noughtCountInCol == fieldDim || noughtCountInRow == fieldDim)
            isNoughtWin = true;
    }

    bool isPrimDiagWin = true;
    bool isSecDiagWin = true;
    for (int i = 1, j = 1; i < fieldDim; i++, j--) {
        auto primDiagElem = cells[i - 1][i - 1];
        auto secDiagElem = cells[i - 1][j + 1];

        if (primDiagElem != cells[i][i])
            isPrimDiagWin = false;
        if (secDiagElem != cells[i][j])
            isSecDiagWin = false;
    }
    if (cells[fieldDim / 2][fieldDim / 2] != csEmpty && (isPrimDiagWin || isSecDiagWin))
        cells[fieldDim / 2][fieldDim / 2] == csCross ? isCrossWin = true : isNoughtWin = true;

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
    assert((*this)[pos] == csEmpty);
    return (*this) + pos;
}

PlayField::CellStatus PlayField::nextMove() const {
    FieldStatus status = checkFieldStatus();
    assert(status == fsNormal);

    int crossesCount = 0, noughtsCount = 0;

    for (int i = 0; i < fieldDim; i++)
        for (int j = 0; j < fieldDim; j++) {
            if (cells[i][j] == csCross)
                crossesCount++;
            else if (cells[i][j] == csNought)
                noughtsCount++;
        }

    if (crossesCount - noughtsCount == 0)
        return csCross;
    else if (crossesCount - noughtsCount == 1)
        return csNought;

    assert(false);
}

PlayField::CellPos::CellPos(int x, int y)  {
    if (!(x >= 0 && x <= 2 && y >= 0 && y <= 2))
        throw "Invalid position!";
    m_x = x;
    m_y = y;
}

int PlayField::CellPos::getX() const  { return  m_x; }

int PlayField::CellPos::getY() const { return m_y; }