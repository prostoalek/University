#include<iostream>
#include "D:\VS solutions\University\2 - Complex\Complex.h"
#include "D:\VS solutions\University\4 - Vector3D\Triad.h"
#include "D:\VS solutions\University\4 - Vector3D\Vector3D.h"

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

	cout << "\nComplex module: " << normObjects[0]->Module() 
		 << "\nComplex norm: " << normObjects[0]->Norma() 
		 << "\nVector module: " << normObjects[1]->Module() 
		 << "\nVector norm: " << normObjects[1]->Norma();


}