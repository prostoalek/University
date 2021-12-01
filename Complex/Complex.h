#ifndef Complex_h
#define Complex_h
#pragma once
#include <conio.h>
#include <ostream>
#include <istream>
#endif // !Complex_h

using namespace std;

class Complex {
private:
	double* A, * B;

public:
	Complex();
	Complex(double a, double b);
	Complex(const Complex& complex);

	~Complex();

	double getA();
	double getB();

	void setA(double a);
	void setB(double b);

	Complex operator+ (Complex& x);
	Complex operator- (Complex& x);
	Complex operator* (Complex& x);
	Complex operator/ (Complex& x);

	bool operator== (Complex& x);
	bool operator!= (Complex& x);
	
	Complex operator= (Complex& x);

	friend ostream& operator<<(ostream&, Complex); 
	friend istream& operator>>(istream&, Complex); 
};


