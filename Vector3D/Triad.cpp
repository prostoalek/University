#include "Triad.h"

Triad::Triad()
{
	A = 0;
	B = 0;
	C = 0;
}

Triad::Triad(double x, double y, double z)
{
	A = x;
	B = y;
	C = z;
}

Triad::Triad(const Triad& triad)
{
	A = triad.A;
	B = triad.B;
	C = triad.C;
}

double Triad::getX()
{
	return A;
}

double Triad::getY()
{
	return B;
}

double Triad::getZ()
{
	return C;
}

void Triad::setX(double x)
{
	A = x;
}

void Triad::setY(double y)
{
	B = y;
}

void Triad::setZ(double z)
{
	C = z;
}

Triad Triad::operator+(double term)
{
	return Triad(A + term, B + term, C + term);
}

Triad Triad::operator+(const Triad& triad)
{
	return Triad(A + triad.A, B + triad.B, C + triad.C);
}

Triad Triad::operator*(double term)
{
	return Triad(A * term, B * term, C * term);
}

bool Triad::operator==(Triad& term)
{
	return A == term.A && B == term.B && C == term.C;
}

bool Triad::operator!=(Triad& term)
{
	return A != term.A || B != term.B || C != term.C;
}

double Triad::Norma()
{
	return 0.0;
}

double Triad::Module()
{
	return 0.0;
}

ostream& operator<<(ostream& out, Triad triad)
{
	double ax, ay, az;
	ax = triad.A;
	ay = triad.B;
	az = triad.C;

	out << "(" << ax << ", " << ay << ", " << az << ")" << "\n";
	return out;
}
