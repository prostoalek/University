#include "Complex.h"
#include <cmath>
#include <string>


Complex::Complex()
{
	A = 0;
	B = 0;
}

Complex::Complex(double a, double b)
{
	A = a;
	B = b;
}

Complex::Complex(const Complex& complex)
{
	A = complex.A;
	B = complex.B;
}

Complex::~Complex()
{
	//
}



double Complex::getA()
{
	return A;
}

double Complex::getB()
{
	return B;
}

void Complex::setA(double a)
{
	A = a;
}

void Complex::setB(double b)
{
	B = b;
}

Complex Complex::operator+(Complex &x)
{
	return Complex(A + x.A, B + x.B);
}

Complex Complex::operator-(Complex& x)
{
	return Complex(A - x.A, B - x.B);;
}

Complex Complex::operator*(Complex& x)
{
	return Complex(A * x.A + B * x.B, B * x.A + A * x.B);
}

Complex Complex::operator/(Complex& x)
{
	return Complex( (A * x.A + B * x.B) / (x.A * x.A + x.B * x.B), (B * x.A - A * x.B) / (x.A * x.A + x.B * x.B));
}

bool Complex::operator==(Complex& x)
{
	return A == x.A && B == x.B;
}

bool Complex::operator!=(Complex& x)
{
	return A != x.A && B != x.B;
}

Complex Complex::operator=(Complex& x)
{
	A = x.A;
	B = x.B;
	return *this;
}

ostream& operator<<(ostream& out, Complex x)
{
	
	out << x.A;
	if (x.B > 0)
		out << "+";
	out << x.B << 'i' << "\n";

	return out;
}

istream& operator>>(istream& in, Complex x)
{
	in >> x.A >> x.B;

	return in;
}
