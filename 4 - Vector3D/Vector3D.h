#ifndef Vector3D_h
#define Vector3D_h
#pragma once
#include "Triad.h"
#include "D:\VS solutions\University\5 - Norm\Norm.h"
#include<iostream>
#include <math.h>
#endif // !Vector3D_h


class Vector3D : public Triad {
public:
	Vector3D() : Triad() {}
	Vector3D(double x, double y, double z) : Triad(x, y, z) {}
	Vector3D(const Vector3D& obj) : Triad(obj) {}

	double scalar(const Vector3D& vector3d);

	double Norma();
	double Module();
};