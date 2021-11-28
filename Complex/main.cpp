#include <iostream>
#include "Complex.h"
#include <complex>

int main() {

	Complex a(2.5, 3.2);
	Complex b(2, 0.8);


	cout << a << b << "\n" << a + b << a - b << a * b << a / b << "\n" << (a != b) << "\n" << (a == b) << "\n\n";

	// swap
	Complex c(a);
	a = b;
	b = c;

	cout << a << b;
}
