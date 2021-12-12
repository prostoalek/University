#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Создайте структуру "Пиратский корабль" которая состоит из полей - название корабля, количество пушек, имя капитана, 
//и состояние коробля - потоплен или нет
//28 Напишите программу, которая считывает данные о кораблях из файла и на базе этих данных строит отсортированный 
//по длинне имен капитанов массив.

struct PirateShip {
	string title;
	int countCannons;
	string captainName;
	bool isSink;
};

int main() {
	ifstream fin("input.txt");

	
}