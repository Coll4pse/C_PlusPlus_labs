#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const {
    if (i < 0 || i > m_size || j < 0 || j > m_size)
        throw "Неккоректная ячейка";
    return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j) {
    if (i < 0 || i > m_size || j < 0 || j > m_size)
        throw "Неккоректная ячейка";
    return matrix[i][j];
}