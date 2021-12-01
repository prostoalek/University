#include "Triad.h"

using namespace std;

Triad::Triad(const Triad& obj)
{
	x = obj.x;
	y = obj.y;
	z = obj.z;
}

Triad Triad::getTriad()
{
	return Triad(x, y, z);
}

Triad Triad::operator+(float number)
{
	Triad result;
	result.x = x + number;
	result.y = y + number;
	result.z = z + number;
	return result;
}

Triad Triad::operator+(Triad triad)
{
	return Triad(this->x + triad.x, this->y + triad.y, this->z + triad.z);
}

Triad Triad::operator*(float number)
{
	Triad result;
	result.x = x * number;
	result.y = y * number;
	result.z = z * number;
	return result;
}
bool Triad::operator==(Triad b)
{
	bool result = false;
	if (x==b.x && y==b.y && z==b.z) result = true;
	return result;
}

ostream& operator<<(ostream& out, Triad obj)
{
	out << "( " << obj.x << ", " << obj.y << ", " <<obj.z << " )\n";
	return out;
}

istream& operator>>(istream& in, Triad triad)
{
	double ax, ay, az;
	ax = triad.x;
	ay = triad.y;
	az = triad.z;

	in >> ax >> ay >> az;
	return in;
}