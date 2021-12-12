#include<iostream>
#include "Vector3D.h"
#include "Triad.h"


int main() {
	setlocale(0, "");

	cout << "Задайте 2 вектора a и b числами\n";

	double q1, q2, q3, p1, p2, p3;
	cin >> q1 >> q2 >> q3 >> p1 >> p2 >> p3;

	Vector3D a(q1, q2, q3), b(p1, p2, p3), c(b), d;

	cout << "\n\na: " << a << "b: " << b << "c: " << c << "d: " << d;

	cout << "\nСумма векторов a и b: \n" << a + b 
		 << "\nСкалярное произведение векторов a и b: \n" << a * b 
	 	 << "\n\nПроизвведение вектора a на 25: \n" << a * 25;

	cout << "\na != b: " << (a != b) << "\nb == c: " << (b == c);

}