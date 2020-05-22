#include "Matrix3D.h"

Matrix3D::Matrix3D(int (&array)[3][3]): Matrix3D() {
    for (int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            matrix[i][j] = array[i][j];
}

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