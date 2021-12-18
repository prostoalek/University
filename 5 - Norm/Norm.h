#ifndef Norm_h
#define Norm_h
#pragma once
#endif // !Norm_h

using namespace std;

class Norm {
protected:
	double A, B, C;

public:

	virtual double Norma() = 0;
	virtual double Module() = 0;

};