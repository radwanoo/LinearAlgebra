#include <iostream>
#include <cmath>
#include "Matrix.h"

constexpr double M_PI = 3.14159265358979323846;
using namespace std;

int main()
{
	vector<double> vec = { 1, 1, 1 };
	Matrix A = A.diag(vec);
	cout << A;
}