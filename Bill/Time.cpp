#include "Time.h"
#include<iostream>

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int a, int b, int c) {
	hour = a;
	minute = b; 
	second = c; 
}

Time::Time(int a) { 
	hour = (a / 3600); 
	minute= (a - hour * 3600) / 60; 
	second = a - hour * 3600 - minute* 60; 
}

Time::Time(const char* str)
{
	string a; int n = 0, obj[3];
	for (int i = 0; i < (strlen(str) + 1); i++)
		if (str[i] != ':' && i != strlen(str))
			a += str[i];
		else
		{
			obj[n] = atoi(a.c_str());

			n++;
			a = "";
		}
	hour = obj[0];
	minute= obj[1];
	second = obj[2];
}

Time Time::operator +(Time& obj)
{
	int _hour = this->hour;
	int _minute = this->minute;
	int _second = this->second;

	_second += obj.second;
	if (_second >= 60)
	{
		_minute++; _second -= 60;
	}

	_minute= _minute+ obj.minute;
	if (_minute>= 60)
	{
		_hour++; _minute-= 60;
	}

	_hour = _hour + obj.hour;

	return Time(_hour, _minute, _second);
}

Time Time::operator-(Time& obj)
{
	int _hour = this->hour;
	int _minute = this->minute;
	int _second = this->second;

	if (this->toSeconds() >- obj.toSeconds()) {

		_second -= obj.second;
		_minute -= obj.minute;
		_hour -= obj.hour;

		while (_second < 0)
		{
			_minute--; _second += 60;
		}

		while (_minute < 0)
		{
			_hour--; _minute += 60;
		}
	}

	return Time(_hour, _minute, _second);
}

Time Time::operator +(int a)
{
	int _hour = this->hour;
	int _minute = this->minute;
	int _second = this->second;

	_second += a;

	if (_second >= 60)
	{
		_minute++; _second -= 60;
	}

	if (_minute>= 60)
	{
		_hour++; _minute-= 60;
	}

	return Time(_hour, _minute, _second);
}

Time Time::operator -(int a)
{
	int _hour = this->hour;
	int _minute = this->minute;
	int _second = this->second;

	if (this->toSeconds() >= a) {
		_second -= a;


		while (_second < 0)
		{
			_minute--; _second += 60;
		}

		while (_minute < 0)
		{
			_hour--; _minute += 60;
		}

		while (_hour < 0)
			_hour++;
	}

	return Time(_hour, _minute, _second);
}

bool Time::operator ==(Time& obj)
{
	if (hour != obj.hour || minute != obj.minute || second != obj.second)
		return true;
	return false;
}

bool Time::operator !=(Time& obj)
{
	if (hour == obj.hour && minute == obj.minute && second == obj.second)
		return false;
	return true;
}

bool Time::operator>(Time& obj)
{
	return this->toSeconds() > obj.toSeconds();
}

bool Time::operator>=(Time& obj)
{
	return this->toSeconds() >= obj.toSeconds();
}

bool Time::operator<(Time& obj)
{
	return this->toSeconds() < obj.toSeconds();
}

bool Time::operator<=(Time& obj)
{
	return this->toSeconds() <= obj.toSeconds();
}


int Time::toSeconds()
{
	return (hour * 3600 + minute* 60 + second);
}

int Time::toMinutes()
{
	return (hour * 60 + minute + (second > 0 ? 1 : 0));
}

string Time::toString()
{
	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}

