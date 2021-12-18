#ifndef Bill_h
#define Bill_h
#pragma once
#include "Time.h"
#include<string>
#endif // !Bill_h

using namespace std;

class Bill {
private:
	string lastName, phoneNumber;
	double feePerMinute, discount, payableAmount;
	Time dialogStartTime, dialogEndTime;

	void setPayableAmount(double _payableAmount);
public:
	Bill();
	Bill(string _lastName, string _phoneNumber, double _feePerMinute, double _discount, Time _dialogStartTime, Time _dialogEndTime);
	
	string getLastName();
	string getPhoneNumber();
	double getFeePerMinute();
	double getDiscount();
	Time getDialogStartTime();
	Time getDialogEndTime();
	double getPayableAmount();

	void setLastName(string _lastName);
	void setPhoneNumber(string _phoneNumber);
	void setFeePerMinute(double _feePerMinute);
	void setDiscount(double _discount);
	void setDialogStartTime(Time _dialogStartTime);
	void setDialogEndTime(Time _dialogEndTime);

	
	void calculatePayableAmount();
	double dialogDurationInMinutes();
	string toString();

};