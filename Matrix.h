#pragma once
#include <vector>
#include <optional>
#include <iostream>
class Matrix
{
	size_t rows;
	size_t cols;	//now I know it was a terrible idea...

	std::vector<std::vector<double>> mainVec;
public:
			//METHODS
	//Constructor:
	Matrix(size_t i = 3, size_t j = 3);

	//"template"? matrices
	static Matrix identity(size_t size);
	static Matrix diag(std::vector<double>& vec);	//replace with vector2 if implemented!

	bool isSquare() const;
	double det() const;
	double cofactorSign(int i, int j) const;
	Matrix transpose() const;
	Matrix inverse() const;
	Matrix minor(int i, int j) const;
	size_t order() const;

			//OPERATORS
	double& operator()(const size_t row, const size_t col);
	//Arithmetic regular:
	Matrix operator+(const Matrix& other) const;
	Matrix operator-() const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const double& scalar) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator/(const double& scalar) const;
	Matrix operator/(const Matrix& other) const;

	//Arithmetic shortened:
	void operator*=(const double& scalar);
	void operator*=(const Matrix& other);
	void operator/=(const double& scalar);
	void operator/=(const Matrix& other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

