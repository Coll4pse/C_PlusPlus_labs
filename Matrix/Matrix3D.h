#ifndef MATRIX_MATRIX3D_H
#define MATRIX_MATRIX3D_H

#include "MatrixBase.h"

class Matrix3D: public MatrixBase {
public:
    Matrix3D(): MatrixBase(m_size) {};
    Matrix3D(int (&array)[3][3]): Matrix3D() {
        for (int i = 0; i < m_size; i++)
            for(int j = 0; j < m_size; j++)
                matrix[i][j] = array[i][j];
    }
    int element(unsigned int i, unsigned int j) const override;
    int& element(unsigned int i, unsigned int j) override;

private:
    static constexpr unsigned int m_size = 3;
    int matrix[m_size][m_size] = {0};
};


#endif //MATRIX_MATRIX3D_H
