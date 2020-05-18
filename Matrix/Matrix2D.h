#ifndef MATRIX_MATRIX2D_H
#define MATRIX_MATRIX2D_H

#include "MatrixBase.h"

class Matrix2D: public MatrixBase {
public:
    Matrix2D(): MatrixBase(m_size) {};

    Matrix2D(int (&array)[2][2]): Matrix2D() {
        for (int i = 0; i < m_size; i++)
            for(int j = 0; j < m_size; j++)
                matrix[i][j] = array[i][j];
    };

    int element(unsigned int i, unsigned int j) const override;
    int& element(unsigned int i, unsigned int j) override;
private:
    static constexpr unsigned int m_size = 2;
    int matrix[m_size][m_size] = {0};
};


#endif //MATRIX_MATRIX2D_H
