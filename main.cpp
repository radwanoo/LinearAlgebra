#include <QApplication>
#include <QWidget>
#include "MainWindow.h"

int main(int argc, char *argv[]) {

	Matrix a(3, 3);
	a(1, 1) = 1;	a(1, 2) = 2;	a(1, 3) = 3;
	a(2, 1) = 4;	a(2, 2) = 5;	a(2, 3) = 6;
	a(3, 1) = 7;	a(3, 2) = 8;	a(3, 3) = 9;
	std::cout << a << std::endl;
	a.swapRows(1, 3);
	std::cout << a << std::endl;
	a.swapCols(1, 3);
	std::cout << a << std::endl;
	return 0;

	//QApplication a(argc, argv);
	//MainWindow w;
	//w.show();

	//return a.exec();
}



/*
using namespace std;

int main()
{
			//Short demo

	Matrix A(2, 2);
	A(1, 1) = -1;	A(1, 2) = 3;	// [-1 3 ]
	A(2, 1) = 3;	A(2, 2) = 4;	// [ 3 4 ]g

	Complex z1(0, sqrt(3)/2);
	z1 += Complex(0.5, 0);	//	z1 = 1/2 + (sqrt3)/2i

	A(1, 1) += z1.mod();	//	|z1| = 1

	cout << A.det();	//	-9
	return 0;
}
*/