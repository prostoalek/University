#include "Complex.h"
#include <cmath>
#include <string>


Complex::Complex()
{
	A = new double(0);
	B = new double(0);
}

Complex::Complex(double a, double b)
{
	A = new double(a);
	B = new double(b);
}

Complex::Complex(const Complex& complex)
{
	A = new double(*complex.A);
	B = new double(*complex.B);
}

Complex::~Complex()
{
	delete[] A;
	delete[] B;
}



double Complex::getA()
{
	return *A;
}

double Complex::getB()
{
	return *B;
}

void Complex::setA(double a)
{
	A = new double(a);
}

void Complex::setB(double b)
{
	B = new double(b);
}

Complex Complex::operator+(Complex &x)
{
	return Complex(*A + *(x.A), *B + *(x.B));
}

Complex Complex::operator-(Complex& x)
{
	return Complex(*A - *(x.A), *B - *(x.B));;
}

Complex Complex::operator*(Complex& x)
{
	return Complex(*A * *(x.A) + *B * *(x.B), *B * *(x.A) + *A * *(x.B));
}

Complex Complex::operator/(Complex& x)
{
	return Complex( (*A * *(x.A) + *B * *(x.B)) / (*(x.A) * *(x.A) + *(x.B) * *(x.B)), (*B * *(x.A) - *A * *(x.B)) / (*(x.A) * *(x.A) + *(x.B) * *(x.B)));
}

bool Complex::operator==(Complex& x)
{
	return *A == *(x.A) && *B == *(x.B);
}

bool Complex::operator!=(Complex& x)
{
	return *A != *(x.A) && *B != *(x.B);
}

Complex Complex::operator=(Complex& x)
{
	A = new double(*x.A);
	B = new double(*x.B);
	return *this;
}

ostream& operator<<(ostream& out, Complex x)
{
	
	out << *(x.A);
	if (*(x.B) > 0)
		out << "+";
	out << *(x.B) << 'i' << "\n";

	return out;
}

istream& operator>>(istream& in, Complex x)
{
	in >> *(x.A) >> *(x.B);

	return in;
}
