#include "Matrix2D.h"

Matrix2D::Matrix2D(): MatrixBase(m_size) {
    for (auto & i : matrix)
        for (int & j : i)
            j = rand() % 10;
}

int Matrix2D::element(unsigned int i, unsigned int j) const {
    return matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j) {
    return matrix[i][j];
}