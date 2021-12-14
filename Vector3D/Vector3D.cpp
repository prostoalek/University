#include "Vector3D.h"

double Vector3D::operator*(const Vector3D& vector3d)
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

double Vector3D::Norma()
{
	return max(max(abs(this->X), abs(this->Y)), abs(this->Z));
}

double Vector3D::Module()
{
	return sqrt((this->X) * (this->X) + (this->Y) * (this->Y) + (this->Z) * (this->Z));
}

//std::ostream& Vector3D::operator<<(std::ostream& out, Vector3D vector3d)
//{
//
//	out << '(' << vector3d.getX() << ", " << vector3d.getY() << ", " << vector3d.getZ() << ")\n";
//	return out;
//}


