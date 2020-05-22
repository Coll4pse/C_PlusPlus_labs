#ifndef MATRIX_MATRIX3D_H
#define MATRIX_MATRIX3D_H

#include "MatrixBase.h"

class Matrix3D: public MatrixBase {
public:
    Matrix3D(): MatrixBase(m_size) {};
    Matrix3D(int (&array)[3][3]);
    int element(unsigned int i, unsigned int j) const override;
    int& element(unsigned int i, unsigned int j) override;

private:
    static constexpr unsigned int m_size = 3;
    int matrix[m_size][m_size] = {0};
};


#endif //MATRIX_MATRIX3D_H
