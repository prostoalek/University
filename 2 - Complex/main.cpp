#include <iostream>
#include "Complex.h"


int main() {

	Complex a(2.5, 3.2);
	Complex b(2, 0.8);
	Complex v(a);

	cout << a.getRe() << "\n";
	cout << a << b << "\n" << a + b << a - b << a * b << a / b << "\n" << (a != b) << "\n" << (a == b) << "\n\n";
	cout << a.getRe() << "\n";

	// swap
	Complex c(a);
	a = b;
	b = c;

	cout << a << b;
}
