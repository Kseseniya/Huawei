#include "Complex.hpp"

complex::complex() : re(0), im(0) {}

complex::complex(double real, double imag) 
{
	re = real;
	im = imag;
}

complex::complex(double num) 
{
	re = num;
	im = 0;
}

complex::complex(complex const &other) 
{
	re = other.re;
	im = other.im;
}

complex::~complex() 
{
	re = 0; im = 0;
}


complex complex::operator=(complex const &other)
{
	re = other.re;
	im = other.im;
	return *this;	
}

complex complex::operator+(complex const &other) const
{
	complex n;
	n.re = re + other.re;
	n.im = im + other.im;
	return n;	
}

complex complex::operator-(complex const &other) const
{
	complex n;
	n.re = re - other.re;
	n.im = im - other.im;
	return n;	
}

complex complex::operator*(complex const &other) const
{
	complex n;
	n.re = (re * other.re) - (im * other.im);
	n.im = (re * other.im) + (im * other.re);
	return n;	
}

complex complex::operator/(complex const &other) const
{
	complex n;

	double div = pow(other.re, 2) + pow(other.im, 2);

	n.re = ((re * other.re) + (im * other.im)) / div;
	n.im = ((im * other.re) - (re * other.im)) / div;
	return n;	
}

complex & complex::operator+=(complex const &other)
{
	re += other.re;
	im += other.im;
	return *this;
}

complex & complex::operator-=(complex const &other)
{
	re -= other.re;
	im -= other.im;
	return *this;
}

complex & complex::operator*=(complex const &other)
{
	complex n;
	n.re = re;
	n.im = im;
	re = (n.re * other.re) - (n.im * other.im);
	im = (n.re * other.im) + (n.im * other.re);
	return *this;	
}

complex & complex::operator/=(complex const &other)
{
	complex n;
	n.re = re;
	n.im = im;

	double div = pow(other.re, 2) + pow(other.im, 2);

	re = ((n.re * other.re) + (n.im * other.im)) / div;
	im = ((n.im * other.re) - (n.re * other.im)) / div;
	return *this;
}

complex & complex::operator-()
{
	re *= -1;
	im *= -1;
	return *this;
}

bool complex::operator==(complex const &other) const
{
	return(re == other.re && im == other.im);
}

bool complex::operator!=(complex const &other) const
{
	return(re != other.re || im != other.im);
}

void complex::printcnum()
{
	if(im == 0)
		std::cout << re << "\n";	
	if(im < 0)
		std::cout << re << " - " << -im << "i\n";
	if(im > 0)
		std::cout << re << " + " << im << "i\n";
}