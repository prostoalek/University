#include<iostream>
#include "Vector3D.h"
#include "Triad.h"


int main() {
	setlocale(0, "");
	//Triad a, b;
	cout << "Создайте 2 вектора числами\n";

	double q1, q2, q3, p1, p2, p3;
	cin >> q1 >> q2 >> q3 >> p1 >> p2 >> p3;

	Vector3D a(q1, q2, q3);
	Vector3D b(p1, p2, p3);

	//cin >> a >> b;
	cout << a + b;


}