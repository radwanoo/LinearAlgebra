#include <iostream>
#include <cmath>
#include "Matrix.h"

constexpr double M_PI = 3.14159265358979323846;
using namespace std;

int main()
{
	Matrix A(2, 2);
	A(1, 1) = 4;	A(1, 2) = 7;
	A(2, 1) = 2;	A(2, 2) = 6;

	cout << "A =\n" << A;
	cout << "\nA^-1 =\n" << A.inverse();

	Matrix B(3, 3);
	B(1, 1) = 1;	B(1, 2) = 2;	B(1, 3) = 3;
	B(2, 1) = 0;	B(2, 2) = 1;	B(2, 3) = 4;
	B(3, 1) = 5;	B(3, 2) = 6;	B(3, 3) = 0;

	cout << "\n\nB =\n" << B;
	cout << "\nB^-1 =\n" << B.inverse();

	Matrix C(4, 4);
	C(1, 1) = 2;	C(1, 2) = 1;	C(1, 3) = 0;	C(1, 4) = 3;
	C(2, 1) = 1;	C(2, 2) = 0;	C(2, 3) = 1;	C(2, 4) = 4;
	C(3, 1) = 3;	C(3, 2) = 2;	C(3, 3) = 1;	C(3, 4) = 0;
	C(4, 1) = 0;	C(4, 2) = 1;	C(4, 3) = 2;	C(4, 4) = 1;

	cout << "\n\nC =\n" << C;
	cout << "\nC^-1 =\n" << C.inverse();
}