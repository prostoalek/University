#ifndef Triad_h
#define Triad_h
#pragma once
#include<iostream>
#include "D:\VS solutions\University\5 - Norm\Norm.h"
#endif // !Triad_h

using namespace std;

class Triad : public Norm {
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

	Triad operator + (double term);
	Triad operator + (const Triad& triad);

	Triad operator * (double term);

	virtual bool operator == (Triad& triad);
	bool operator != (Triad& triad);

	friend ostream& operator<<(ostream&, Triad);

private:
	double Norma();
	double Module();
};
