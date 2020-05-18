#include "Matrix2D.h"

int Matrix2D::element(unsigned int i, unsigned int j) const {
    if (i < 0 || i > m_size || j < 0 || j > m_size)
        throw "Неккоректная ячейка";
    return matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j) {
    if (i < 0 || i > m_size || j < 0 || j > m_size)
            throw "Неккоректная ячейка";
    return matrix[i][j];
}