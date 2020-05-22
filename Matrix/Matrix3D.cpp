#include "Matrix3D.h"

Matrix3D::Matrix3D(): MatrixBase(m_size) {
    for (auto & i : matrix)
        for (int & j : i)
            j = rand() % 10;
}

int Matrix3D::element(unsigned int i, unsigned int j) const {
    return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j) {
    return matrix[i][j];
}