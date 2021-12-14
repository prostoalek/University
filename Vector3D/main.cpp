#include<iostream>
#include "Vector3D.h"
#include "Triad.h"


int main() {
	setlocale(0, "");

	cout << "Задайте 2 вектора a и b числами\n";

	double q1, q2, q3, p1, p2, p3;
	cin >> q1 >> q2 >> q3 >> p1 >> p2 >> p3;

	Vector3D a(q1, q2, q3), b(p1, p2, p3), c(b);
	
	// умножение на число
	Triad* A = new Vector3D(a);
	Triad* midMultiplicationOnNum = new Vector3D;
	
	*midMultiplicationOnNum = *A * 25;
	Vector3D* endMultiplicationOnNum = dynamic_cast<Vector3D*>(midMultiplicationOnNum);
	
	// сложение
	Triad* midSum = new Vector3D;
	*midSum = a + b;
	Vector3D* endSum = dynamic_cast<Vector3D*>(midSum);

	cout << "\n\na: " << a << "b: " << b << "c: " << c;

	cout << "\nСумма векторов a и b: \n" << *endSum
		 << "\nСкалярное произведение векторов a и b: \n" << a * b
	 	 << "\n\nПроизвведение вектора a на 25: \n" << *endMultiplicationOnNum;

	cout << "\na != b: " << (a != b) << "\nb == c: " << (b == c);

}