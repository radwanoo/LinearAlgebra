#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

#define TEST_RET return 0	//For compiling with unfinished methods.

Matrix::Matrix(size_t i, size_t j) : rows(i), cols(j) {
	mainVec.resize(rows);
	for (int a = 0; a < rows; a++) {
		for(int b = 0; b < cols; b++) {
			mainVec[a].push_back(0);
		}
	}
}

Matrix Matrix::identity(size_t size) {
	Matrix result(size, size);
	for (int a = 0; a < size; a++) {
		result.mainVec[a][a] = 1;
	}
	return result;
}

Matrix Matrix::diag(std::vector<double>& vec) {
	size_t matOrder = vec.size();
	Matrix result(matOrder, matOrder);
	for (int a = 0; a < vec.size(); a++) {
		result.mainVec[a][a] = vec[a];
	}
	return result;
}

bool Matrix::isSquare() const{
	return (cols == rows);
}

double Matrix::det() const{
	if (!isSquare()) throw std::invalid_argument("The matrix must be square!");
	if (rows == 1) return mainVec[0][0];
	else if (rows == 2) return (mainVec[0][0] * mainVec[1][1]) - (mainVec[1][0] * mainVec[0][1]);
	else {
		double result = 0;
		for (int i = 0; i < cols; i++) {	//Recurrent Laplace expansion?
			result += mainVec[0][i] * minor(1, i + 1).det() * cofactorSign(1, i + 1);
			//std::cout << "cofactor:" << mainVec[0][i] << "\nMinor:\n" << minor(1, i + 1) << "\ndet: " << minor(1, i + 1).det() <<
			//	"\nsign: " << laplaceSign(1, i + 1) << "\nresult = " << result << "\n\n\n";
		}
		return result;
	}
}

double Matrix::cofactorSign(int i, int j) const {
	return pow(-1, (i + j));
}

Matrix Matrix::transpose() const {
	Matrix newMat(cols, rows);
	for (int a = 0; a < newMat.rows; a++) {
		for (int b = 0; b < newMat.cols; b++) {
			newMat.mainVec[a][b] = mainVec[b][a];
		}
	}
	return newMat;
}

Matrix Matrix::inverse() const {
	//check if inverse is possible
	if (!isSquare()) throw std::invalid_argument("The matrix must be square!");
	if (det() == 0) throw std::invalid_argument("The determinant is 0!");
	Matrix inverse(order(), order());
	double det1 = det();
	if (order() == 2) {			//utilizing the 2x2 inverse matrix formula
		inverse.mainVec[0][0] = mainVec[1][1];
		inverse.mainVec[0][1] = -mainVec[0][1];
		inverse.mainVec[1][0] = -mainVec[1][0];
		inverse.mainVec[1][1] = mainVec[0][0];
		return inverse * (1/det1);
	}
	else {
		for (int a = 0; a < order(); a++) {			//adjugate method, highly ineffective, esp for bigger matrices
			for (int b = 0; b < order(); b++) {
				inverse.mainVec[a][b] = minor(a + 1, b + 1).det() * cofactorSign(a + 1, b + 1);
			}
		}
		inverse *= (1/det1);
		return inverse.transpose();
	}
}

Matrix Matrix::minor(int i, int j) const {
	if (i > rows || j > cols || i < 1 || j < 1) throw std::invalid_argument("Invalid col/row index!");
	if (rows == 1 || cols == 1) {
		Matrix res(1, 1);
		res(1, 1) = mainVec[0][0];
		return res;		//if 1x1 matrix, return it back
	}
	Matrix result(rows, cols);
	result.mainVec = mainVec;
	result.mainVec.erase(result.mainVec.begin() + i - 1);	//remove j-th column
	for (int a = 0; a < result.cols-1; a++) {		//remove i-th row in every column
		result.mainVec[a].erase(result.mainVec[a].begin() + j - 1);
	}
	result.rows -= 1;
	result.cols -= 1;
	return result;
}

size_t Matrix::order() const {
	if (cols != rows) throw std::invalid_argument("The matrix must be square!");
	return rows;
}

double& Matrix::operator()(const size_t row, const size_t col) {
	return mainVec[(row - 1)][(col - 1)];
}

Matrix Matrix::operator+(const Matrix& other) const {
	if (rows != other.rows || cols != other.cols) {
		throw std::invalid_argument("Matrices must be the same size!");
	}
	Matrix result(rows, cols);
	for (int a = 0; a < result.cols; a++) {
		for (int b = 0; b < result.rows; b++) {
			result.mainVec[a][b] = mainVec[a][b] + other.mainVec[a][b];
		}
	}
	return result;
}

Matrix Matrix::operator-() const {
	return (*this) * (-1);
}

Matrix Matrix::operator-(const Matrix& other) const {
	return operator+(-other);
}

Matrix Matrix::operator*(const double& scalar) const {
	Matrix result(rows,cols);
	for (int i = 0; i < result.rows; i++) {
		for (int j = 0; j < result.cols; j++) {
			result.mainVec[i][j] = mainVec[i][j] * scalar;
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
	if (cols != other.rows)  throw std::invalid_argument("Matrix sizes don't match!");
	Matrix result(rows, other.cols);
	//iterate by each of the first matrix columns
	for (int i = 0; i < result.rows; i++) {
		for (int j = 0; j < result.cols; j++) {	//operate on a particular matrix cell
			double cellResult = 0;
			for (int k = 0; k < cols; k++) {
				cellResult += mainVec[i][k] * other.mainVec[k][j];
			}
			result.mainVec[i][j] = cellResult;
		}
	}
	return result;
}


Matrix Matrix::operator/(const double& scalar) const {
	return (*this) * (1 / scalar);
}

Matrix Matrix::operator/(const Matrix& other) const {
	if (det() == 0 || other.det() == 0) throw std::invalid_argument("The determinant is 0!");
	return (*this).operator*(other.inverse());
}

void Matrix::swapRows(int row1, int row2) {
	std::swap(mainVec[row1 - 1], mainVec[row2 - 1]);
}

void Matrix::swapCols(int col1, int col2) {
	for (int i = 0; i < mainVec[0].size(); i++) {
		std::swap(mainVec[i][col1 - 1], mainVec[i][col2 - 1]);
	}
}

void Matrix::operator*=(const double& scalar) {
	for (std::vector<double>& vec : mainVec) {
		for (double& a : vec) {
			a *= scalar;
		}
	}
}

void Matrix::operator*=(const Matrix& other) {
	if (cols != other.rows) throw std::invalid_argument("Matrix sizes don't match!");
	*this = (*this) * other;

}

void Matrix::operator/=(const double& scalar) {
	*this = (*this).operator/(scalar);
}

void Matrix::operator/=(const Matrix& other) {
	*this = (*this).operator/(other);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
	for (int a = 0; a < mat.rows; a++) {
		os << "[";
		for (int b = 0; b < mat.cols; b++) {
			os << mat.mainVec[a][b] << ", ";
		}
		os << "]\n";
	}
	return os;
}
