#include<iostream>
#include "D:\VS solutions\University\Complex\Complex.h"
#include "D:\VS solutions\University\Vector3D\Triad.h"
#include "D:\VS solutions\University\Vector3D\Vector3D.h"

int main() {
	setlocale(0, "");

	double v1, v2, v3, c1, c2;
	
	cout << "¬ведите действительную и мнимую части комплексного числа: ";
	cin >> c1 >> c2;
	cout << "\n";

	cout << "¬ведите координаты вектора: ";
	cin >> v1 >> v2 >> v3;
	cout << "\n";

	Norm* normObjects[] = {
		new Complex(c1, c2),
		new Vector3D(v1, v2, v3)
	};

	Complex* C = dynamic_cast<Complex*>(normObjects[0]);
	Vector3D* V = dynamic_cast<Vector3D*>(normObjects[1]);

	cout << "Complex c: " << *C
		 << "\nVector v: " << *V << "\n"
		 << "\nComplex module: " << normObjects[0]->Module() 
		 << "\nComplex norm: " << normObjects[0]->Norma() 
		 << "\nVector module: " << normObjects[1]->Module() 
		 << "\nVector norm: " << normObjects[1]->Norma();


}