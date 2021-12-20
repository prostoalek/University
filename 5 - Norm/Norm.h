#ifndef Norm_h
#define Norm_h
#pragma once
#endif // !Norm_h

using namespace std;

class Norm {
protected:
	double A, B, C;
	
	Norm() : A(0), B(0), C(0) {}
	Norm(double a, double b, double c) : A(a), B(b), C(c) {}
	Norm(const Norm& norm) : A(norm.A), B(norm.B), C(norm.C) {}

public:

	virtual double Norma() = 0;
	virtual double Module() = 0;

};