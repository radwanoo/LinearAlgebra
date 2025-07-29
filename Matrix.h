#pragma once
#include <vector>
#include <optional>
#include <iostream>
class Matrix
{
	int rows;
	int cols;	//now I know it was a terrible idea...

	std::vector<std::vector<double>> mainVec;
public:
	Matrix(int i = 3, int j = 3);
	Matrix identity(int size);
	bool isSquare() const;
	double det() const;
	int laplaceSign(int i, int j) const;
	Matrix transpose() const;
	Matrix inverse() const;
	Matrix minor(int i, int j) const;
	size_t order() const;
	double& operator()(const size_t row, const size_t col);
	Matrix operator+(const Matrix& other) const;
	Matrix operator*(const double& scalar) const;
	void operator*=(const double& scalar);
	Matrix operator*(const Matrix& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

