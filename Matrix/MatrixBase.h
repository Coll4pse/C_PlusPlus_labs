#ifndef MATRIX_MATRIXBASE_H
#define MATRIX_MATRIXBASE_H
#include <fstream>

class MatrixBase {
public:
    MatrixBase() = delete;
    unsigned int size() const { return m_size; }
    virtual int element(unsigned int i, unsigned int j) const = 0;
    virtual int& element(unsigned int i, unsigned int j) = 0;
    void operator*=(int iMult);
    void operator+=(MatrixBase& iAdd) ;

protected:
    explicit MatrixBase(unsigned int iSize): m_size(iSize) {};

private:
    const unsigned int m_size;
};

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);

#endif //MATRIX_MATRIXBASE_H
