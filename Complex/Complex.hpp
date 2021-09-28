#ifndef COMPLEX_HPP
#define COMPLEX_HPP


#include <cmath>
#include <iostream>

struct complex
{
	double re;
	double im;

	complex();
	complex(double real, double imag);
	complex(complex const &other);
	complex(double num);
	~complex();

	complex operator=(complex const &other);
	complex operator+(complex const &other)const;
	complex operator-(complex const &other)const;
	complex operator*(complex const &other)const;
	complex operator/(complex const &other)const;

	complex & operator+=(complex const &other);
	complex & operator-=(complex const &other);
	complex & operator*=(complex const &other);
	complex & operator/=(complex const &other);

	complex & operator-();

	bool operator==(complex const &other)const;
	bool operator!=(complex const &other)const;

	void printcnum();

};

#endif
