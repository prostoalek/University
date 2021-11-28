#include <iostream>
#include "ModelWindow.h"

using namespace std;

int main()
{
	ModelWindow currentW;
	ModelWindow otherW("BigWindow3000", "#010101", 0, 2, 1600, 900, true, false);

	cout << currentW.ToString() << "\n\n" << otherW.ToString() << "\n";

	currentW.Move(100, 250);
	otherW.Resize(500, 500);
	currentW.ChangeColor("#203943");
	otherW.ChangeVisibility();

	cout << "\n" << currentW.ToString() << "\n\n" << otherW.ToString() << "\n";



}