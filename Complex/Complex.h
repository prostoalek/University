#ifndef Complex_h
#define Complex_h
#pragma once
#include "D:\VS solutions\University\5 - Norm\Norm.h"
#include <conio.h>
#include <ostream>
#include <istream>
#include <math.h>
#endif // !Complex_h

using namespace std;

class Complex : public Norm {

public:
	Complex();
	Complex(double re, double im);
	Complex(const Complex& complex);

public:
	double getRe();
	double getIm();

	void setRe(double re);
	void setIm(double im);

	Complex operator+ (Complex& x);
	Complex operator- (Complex& x);
	Complex operator* (Complex& x);
	Complex operator/ (Complex& x);

	bool operator== (Complex& complex);
	bool operator!= (Complex& complex);
	
	Complex operator= (Complex& complex);

	friend ostream& operator<<(ostream&, Complex);
	friend istream& operator>>(istream&, Complex); 

	double Norma();
	double Module();
	
};


