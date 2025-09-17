#include <QApplication>
#include <QWidget>
#include "MainWindow.h"

int main(int argc, char *argv[]) {


	Matrix a(2,2);
	a(1, 1) = 0; a(1, 2) = -1;
	a(2, 1) = 1; a(2, 2) = 0;
	std::vector<double> eigen = a.eigenvalues();
	for (double d : eigen) {
		std::cout << d << "\n";
	}
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