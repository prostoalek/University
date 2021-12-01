#ifndef Triad_h
#define Triad_h
#pragma once
#include<iostream>
#endif // !Triad_h

using namespace std;

class Triad {
protected:
	double X, Y, Z;

public:
	
	Triad();
	Triad(double x, double y, double z);
	Triad(const Triad& triad);

	double getX();
	double getY();
	double getZ();

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	Triad getTriad();

	Triad operator + (double term);
	Triad operator + (Triad triad);
	Triad operator * (double term);

	bool operator == (Triad& term);
	bool operator != (Triad& term);


	friend ostream& operator<<(ostream&, Triad);
	//friend istream& operator>>(istream&, Triad);
};