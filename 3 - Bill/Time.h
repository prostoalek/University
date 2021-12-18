#ifndef Time_h
#define Time_h
#pragma once
#include<string>
#endif // !Time_h

using namespace std;

class Time {
	int hour, minute, second;

public:
	Time();
	Time(int _hour, int _minute, int _second);
	Time(int _second);
	Time(const char* str);

	int getHour();
	int getMinute();
	int getSecond();

	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	Time operator +(Time& obj);
	Time operator -(Time& obj);
	Time operator +(int _second);
	Time operator -(int _second);
	bool operator ==(Time& obj);
	bool operator !=(Time& obj);
	bool operator >(Time& obj);
	bool operator >=(Time& obj);
	bool operator <(Time& obj);
	bool operator <=(Time& obj);

	int toSeconds();
	int toMinutes();
	string toString();
};
