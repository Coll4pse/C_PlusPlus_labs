#include <iostream>
#include "MatrixBase.h"

void MatrixBase::operator+=(MatrixBase& iAdd) {
    if (iAdd.size() != m_size)
        throw "Матрицы разных размеров. Сложение невозможно";

    for (int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            element(i, j) += iAdd.element(i, j);
}

void MatrixBase::operator*=(int iMult) {
    for (int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            element(i, j) *= iMult;
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix) {
    for (int i = 0; i < iMatrix.size(); i++) {
        for (int j = 0; j < iMatrix.size(); j++) {
            stream << iMatrix.element(i, j) << " | ";
        }
        stream << std::endl << "--------------" << std::endl;
    }
    return stream;
}