#pragma once
#include<iostream>
#include"Triad.h"

using namespace std;

class vector3D:public Triad {
public:
	vector3D() {};
	vector3D(float x, float y, float z) :Triad(x, y, z) {};
	vector3D(const vector3D& obj) : Triad(obj) {};

	vector3D operator+(const vector3D& b);
	float operator*(const vector3D& b);
	
	friend ostream& operator<<(std::ostream& out, vector3D obj);
	friend istream& operator>>(istream&, vector3D);
};