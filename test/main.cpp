#include<iostream>
#include "Triad.h"
#include "vector3D.h"

int main() {

	setlocale(0, "");
	//Triad a, b;
	cout << "Создайте 2 вектора числами\n";

	//double q1, q2, q3, p1, p2, p3;
	//cin >> q1 >> q2 >> q3 >> p1 >> p2 >> p3;

	//vector3D a(q1, q2, q3);
	//vector3D b(p1, p2, p3);

	////cin >> a >> b;
	//cout << a + b;

	Triad a, b;

	cin >> a >> b;
	cout << a << b << "\n";
	cout << a + b;
}