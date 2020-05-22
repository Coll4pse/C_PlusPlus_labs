#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main() {
    srand(time(0));

    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;

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
