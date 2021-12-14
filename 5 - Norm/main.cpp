#include<iostream>
#include "D:\VS solutions\University\Complex\Complex.h"
#include "D:\VS solutions\University\Vector3D\Triad.h"
#include "D:\VS solutions\University\Vector3D\Vector3D.h"

//using namespace std;

int main() {

	Complex c(2.5, 3.2);

	double q1, q2, q3, p1, p2, p3;
	cin >> q1 >> q2 >> q3;
	Vector3D v(q1, q2, q3);

	cout << "complex c: " << c << "\nvector v: " << v << "\n";
	cout << "Complex module: " << c.Module() << "\nXomplex norm: " << c.Norma() << "\nVector module: "
		 << v.Module() << "\nVector norm: " << v.Norma();


}