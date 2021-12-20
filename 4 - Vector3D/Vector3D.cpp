#include "Vector3D.h"

double Vector3D::scalar(const Vector3D& vector3d)
{
	double ax, ay, az, bx, by, bz;
	ax = this->A;
	ay = this->B;
	az = this->C;
	bx = vector3d.A;
	by = vector3d.B;
	bz = vector3d.C;

	return ax * bx + ay * by + az * bz;
}

double Vector3D::Norma()
{
	return max(max(abs(A), abs(B)), abs(C));
}

double Vector3D::Module()
{
	return sqrt((A) * (A) + (B) * (B) + (C) * (C));
}



