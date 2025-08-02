#include <iostream>
#include <cmath>
#include "Matrix.h"
#include "Complex.h"
#include "Constants.h"

using namespace std;

int main()
{
	Complex z1(2,3);
	z1 += Complex(2, 0);
	cout << z1.mod();
}