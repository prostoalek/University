#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
    currentYear = 2021;
}

Date::Date(string date) {
    string day, month, year;


    day = date.substr(0, date.find("."));
    date.erase(0, date.find(".") + 1);
    month = date.substr(0, date.find("."));
    year = date.erase(0, date.find(".") + 1);


    this->day = atoi(day.c_str());
    this->month = atoi(month.c_str());
    this->year = atoi(year.c_str());
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::Display() {
    cout << "Год: " << year << endl;
    cout << "Месяц: " << month << endl;
    cout << "День: " << day << endl;
}

void Date::Read() {
    string date, day, month, year;
    cin >> date;

    day = date.substr(0, date.find("."));
    date.erase(0, date.find(".") + 1);
    month = date.substr(0, date.find("."));
    year = date.erase(0, date.find(".") + 1);


    this->day = atoi(day.c_str());
    this->month = atoi(month.c_str());
    this->year = atoi(year.c_str());
}

unsigned int Date::Stazh() {
    return (this->currentYear - this->year);
}