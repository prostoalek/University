#pragma once
#include<iostream>

using namespace std;

class Triad {
protected:
	float x;
	float y;
	float z;
public:
	Triad() : x(0), y(0), z(0) {};
	Triad(float x, float y, float z) :x(x), y(y), z(z) {};
	Triad(const Triad& obj);

	Triad getTriad();

	Triad operator+(float number);
	Triad operator + (Triad triad);
	Triad operator*(float number);
	bool operator==(Triad b);

	float getX() { return x; };
	float getY() { return y; };
	float getZ() { return z; };

	friend ostream& operator<<(std::ostream& out, Triad obj);
	friend istream& operator>>(std::istream&, Triad);
};