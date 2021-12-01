#include"vector3D.h"

using namespace std;

vector3D vector3D::operator+(const vector3D& b) {
	vector3D res;
	res.x =x + b.x;
	res.y =y + b.y;
	res.z =z + b.z;
	return res;
}

float vector3D::operator*(const vector3D& b)
{
	return (x * b.x + y * b.y + z * b.z);
}

ostream& operator<<(ostream& out, vector3D obj)
{
	out << "( " << obj.getX() << ", " << obj.getY() << ", " << obj.getZ()<< " )\n";
	return out;
}

istream& operator>>(istream& in, vector3D vector3d)
{
	in >> vector3d.getTriad();
	return in;
}
