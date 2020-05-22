#ifndef MATRIX_MATRIX2D_H
#define MATRIX_MATRIX2D_H

#include "MatrixBase.h"

class Matrix2D: public MatrixBase {
public:
    Matrix2D();
    int element(unsigned int i, unsigned int j) const override;
    int& element(unsigned int i, unsigned int j) override;

private:
    static constexpr unsigned int m_size = 2;
    int matrix[m_size][m_size] = {0};
};


#endif //MATRIX_MATRIX2D_H
