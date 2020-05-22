#include "Matrix2D.h"

Matrix2D::Matrix2D(int (&array)[2][2]): Matrix2D() {
    for (int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            matrix[i][j] = array[i][j];
}

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