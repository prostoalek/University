#include "Triad.h"

Triad::Triad()
{
	X = 0;
	Y = 0;
	Z = 0;
}

Triad::Triad(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

Triad::Triad(const Triad& triad)
{
	X = triad.X;
	Y = triad.Y;
	Z = triad.Z;
}

double Triad::getX()
{
	return X;
}

double Triad::getY()
{
	return Y;
}

double Triad::getZ()
{
	return Z;
}

void Triad::setX(double x)
{
	X = x;
}

void Triad::setY(double y)
{
	Y = y;
}

void Triad::setZ(double z)
{
	Z = z;
}

Triad Triad::getTriad()
{
	return Triad(X, Y, Z);
}

Triad Triad::operator+(double term)
{
	return Triad(this->X + term, this->Y + term, this->Z + term);
}

Triad Triad::operator+(Triad triad)
{
	return Triad(this->X + triad.X, this->Y + triad.Y, this->Z + triad.Z);
}

Triad Triad::operator*(double term)
{
	return Triad(this->X * term, this->Y * term, this->Z * term);
}

bool Triad::operator==(Triad& term)
{
	return this->X == term.X && this->Y == term.Y && this->Z == term.Z;
}

bool Triad::operator!=(Triad& term)
{
	return this->X != term.X || this->Y != term.Y || this->Z != term.Z;
}

ostream& operator<<(ostream& out, Triad triad)
{
	double ax, ay, az;
	ax = triad.X;
	ay = triad.Y;
	az = triad.Z;

	out << "(" << ax << ", " << ay << ", " << az << ")" << "\n";
	return out;
}

//istream& operator>>(istream& in, Triad triad)
//{
//	double ax, ay, az;
//	ax = triad.X;
//	ay = triad.Y;
//	az = triad.Z;
//
//	in >> ax >> ay >> az;
//	return in;
//}