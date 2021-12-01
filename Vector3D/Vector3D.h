#ifndef Vector3D_h
#define Vector3D_h
#pragma once
#include "Triad.h"
#endif // !Vector3D_h

class Vector3D : public Triad{
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(const Vector3D& obj) : Triad(obj) {}
	Vector3D(const Triad& obj) : Triad(obj) {}

	Vector3D operator + (Vector3D& vector3d);
	double operator * (Vector3D& vector3d);

	friend ostream& operator<<(ostream&, Vector3D);
	friend istream& operator>>(istream&, Vector3D);

};