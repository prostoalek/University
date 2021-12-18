#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Создайте структуру "Пиратский корабль" которая состоит из полей - название корабля, количество пушек, имя капитана, 
//и состояние коробля - потоплен или нет
//28 Напишите программу, которая считывает данные о кораблях из файла и на базе этих данных строит отсортированный 
//по длинне имен капитанов массив.
// 
//ТопФлот3000, 30, Аркаша, нет
//Морской городок, 10, Геннадий Викторович, да
//ProMaxLuxaryVillage, 50, Nubmaster69, no
//Ship, 40, Morphling, yes

struct PirateShip {
	string title;
	int countCannons;
	string captainName;
	bool isSink;
};

int main() {
	setlocale(0, "");

	ifstream fin("input.txt");

	int i = 0, first, second, third, n;
	

	string str, name, strN;

	getline(fin, strN);
	n = stoi(strN);
	string* info = new string[n];
	int* nameLength = new int();
	

	while (getline(fin, str)) {
		*(info + i) = str;

		first = str.find(','); 
		second = str.find(',', first + 1);
		third = str.find(',', second + 1);
		name = str.substr(second + 2, third - second - 2);
		*(nameLength + i) = name.length();

		i++;
	}

	for (i = 0; i < n; i++)
	{
		cout << *(info + i) << "\n";
	}

	
	for (i = 0; i < n - 1; i++)
	{
		int smallestIndex = i;

		for (int j = i + 1; j < n; ++j)
		{
			if (*(nameLength + j) < *(nameLength + smallestIndex))
				smallestIndex = j;
		}

		swap(*(nameLength + i), *(nameLength + smallestIndex));
		swap(*(info + i), *(info + smallestIndex));
	}
	
	
	for (i = 0; i < n; i++)
	{
		cout << "\n" << *(info + i);
	}

	delete[] info;
	delete[] nameLength;
}