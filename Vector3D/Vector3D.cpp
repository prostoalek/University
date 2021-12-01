#include "Vector3D.h"

Vector3D::Vector3D()
{
	Triad();
}

Vector3D::Vector3D(double x, double y, double z)
{
	Triad(x, y, z);
}



Vector3D Vector3D::operator+(Vector3D& obj)
{
	return Vector3D(this->getTriad() + obj.getTriad());
}

double Vector3D::operator*(Vector3D& vector3d)
{
	double ax, ay, az, bx, by, bz;
	ax = this->X;
	ay = this->Y;
	az = this->Z;
	bx = vector3d.X;
	by = vector3d.Y;
	bz = vector3d.Z;

	return ax * bx + ay * by + az * bz;
}

ostream& operator<<(ostream& out, Vector3D vector3d)
{
	out << vector3d.getTriad();
	return out;
}

istream& operator>>(istream& in, Vector3D vector3d)
{
	in >> vector3d.getTriad();
	return in;
}
