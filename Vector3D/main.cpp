#include<iostream>
#include "Vector3D.h"
#include "Triad.h"


int main() {
	setlocale(0, "");

	cout << "������� 2 ������� a � b �������\n";

	double q1, q2, q3, p1, p2, p3;
	cin >> q1 >> q2 >> q3 >> p1 >> p2 >> p3;

	Vector3D a(q1, q2, q3), b(p1, p2, p3), c(b), d;

	cout << "\n\na: " << a << "b: " << b << "c: " << c << "d: " << d;

	cout << "\n����� �������� a � b: \n" << a + b 
		 << "\n��������� ������������ �������� a � b: \n" << a * b 
	 	 << "\n\n������������� ������� a �� 25: \n" << a * 25;

	cout << "\na != b: " << (a != b) << "\nb == c: " << (b == c);

}