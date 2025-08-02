#include "Complex.h"
#include "Constants.h"
#define TEST_RET return 0

Complex::Complex(double r, double i) : re(r), im(i) {}

Complex Complex::fromPolar(double r, double phi) {

	TEST_RET;
}

double Complex::getReal() const {
	return re;
}

double Complex::getImag() const {
	return im;
}

void Complex::setReal(const double& val) {
	re = val;
}

void Complex::setImag(const double& val) {
	im = val;
}

double Complex::mod() const {
	return sqrt(re*re + im*im);
}

double Complex::arg() const {
	return atan2(im, re);
}

Complex Complex::conj()  const {
	return { re, -im };
}

Complex Complex::operator+(const Complex& other) const {
	return { re + other.re, im + other.im };
}

Complex Complex::operator-() const {
	return { -re, -im };
}

Complex Complex::operator-(const Complex& other) const {
	return { re - other.re, im - other.im };
}

Complex Complex::operator*(const Complex& other) const {
	return { (re * other.im - im * other.im), (re * other.im + im * other.re) };
}

Complex Complex::operator/ (const Complex & other) const {
	double a = re, b = im,
		c = other.re, d = other.im,
		denom = c*c + d*d;

	return{ ((a * c + b * d) / denom), ((b*c-a*d)/denom)};
}

void Complex::operator+=(const Complex& other) {
	*this = (*this) + other;
}

void Complex::operator-=(const Complex& other) {
	*this = (*this) - other;
}

void Complex::operator*=(const Complex& other) {
	*this = (*this) * other;
}

void Complex::operator/=(const Complex& other) {
	*this = (*this) / other;
}

std::ostream& operator<<(std::ostream& os, const Complex& obj) {
	if (!obj.re && !obj.im) os << "0";
	if (obj.re) os << obj.re;
	if (obj.im) {
		if (obj.im > 0) os << " + ";
		else os << " - ";
		os << abs(obj.im) << "i";
	} 
	return os;
}