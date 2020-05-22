#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main() {
    int d21[2][2] = {
            {1, 2},
            {3, 4}
    };

    int d22[2][2] = {
            {43, 24},
            {82, 0}
    };

    int d31[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int d32[3][3] = {
            {-4, 2, 9},
            {0, 0, 0},
            {24, 71, 1}
    };

    Matrix2D m2a = d21, m2b = d22;
    Matrix3D m3a = d31, m3b = d32;

    cout << "m2a = " << endl << m2a << endl
    << "m2b = " << endl << m2b << endl
    << "m3a = " << endl << m3a << endl
    << "m3b = " << endl << m3b << endl;

    m2a += m2b;
    m3a += m3b;

    cout << "m2a + m2b = " << endl << m2a << endl
    << "m3a + m3b = " << endl << m3a << endl;

    m2b *= 10;
    m3b *= 10;

    cout << "m2b * 10 = " << endl << m2b << endl
    << "m3b * 10 = " << endl << m3b << endl;
}
