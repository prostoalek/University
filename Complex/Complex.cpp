#include "Complex.h"
#include <cmath>
#include <string>


Complex::Complex()
{
	A = 0;
	B = 0;
	C = 0;
}

Complex::Complex(double re, double im)
{
	A = re;
	B = im;
	C = 0;
}

Complex::Complex(const Complex& complex)
{
	A = complex.A;
	B = complex.B;
	C = 0;
}

Complex::~Complex()
{
	
}



double Complex::getRe()
{
	return A;
}

double Complex::getIm()
{
	return B;
}

void Complex::setRe(double re)
{
	A = re;
}

void Complex::setIm(double im)
{
	B = im;
}

Complex Complex::operator+(Complex &complex)
{
	return Complex(A + complex.A, B + complex.B);
}

Complex Complex::operator-(Complex& complex)
{
	return Complex(A - complex.A, B - complex.B);
}

Complex Complex::operator*(Complex& complex)
{
	return Complex(A * complex.A + B * complex.B, B * complex.A + A * complex.B);
}

Complex Complex::operator/(Complex& complex)
{
	return Complex( (A * complex.A + B * complex.B) / (complex.A * complex.A + complex.B * complex.B), (B * complex.A - A * complex.B) / (complex.A * complex.A + complex.B * complex.B));
}

bool Complex::operator==(Complex& complex)
{
	return A == complex.A && B == complex.B;
}

bool Complex::operator!=(Complex& complex)
{
	return A != complex.A && B != complex.B;
}

Complex Complex::operator=(Complex& complex)
{
	A = complex.A;
	B = complex.B;
	return *this;
}

double Complex::Norma()
{
	return A * A + B * B;
}

double Complex::Module()
{
	return sqrt(this->Norma());
}

ostream& operator<<(ostream& out, Complex complex)
{
	
	out << complex.A;
	if (complex.B > 0)
		out << "+";
	out << complex.B << 'i' << "\n";

	return out;
}

istream& operator>>(istream& in, Complex complex)
{
	in >> complex.A >> complex.B;

	return in;
}
