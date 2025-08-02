#pragma once
#include <cmath>
#include <iostream>
class Complex
{
	double re;
	double im;
public:
		//CONSTRUCTORS
	Complex(double r = 0, double i = 0);
	//not a constructor per se, but take from
	//polar coordinates
	Complex fromPolar(double r, double phi);
		//METHODS
	//	getters / setters
	double getReal() const;
	double getImag() const;
	void setReal(const double& val);
	void setImag(const double& val);

	//complex properties
	double mod() const;
	double arg() const;
	Complex conj() const;

	//Arithmetics
	Complex operator+(const Complex& other) const;
	Complex operator-() const;	//unary
	Complex operator-(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex operator/(const Complex& other) const;

	void operator+=(const Complex& other);
	void operator-=(const Complex& other);
	void operator*=(const Complex& other);
	void operator/=(const Complex& other);


	//cout
	friend std::ostream& operator<<(std::ostream& os,  const Complex& obj);
};
