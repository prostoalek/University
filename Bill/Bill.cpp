#include "Bill.h"

void Bill::setPayableAmount(double _payableAmount)
{
	payableAmount = _payableAmount;
}

Bill::Bill()
{
	lastName = "Pupkin";
	phoneNumber = "88005553535";
	feePerMinute = 0;
	discount = 0;
	dialogStartTime = Time();
	dialogEndTime = Time();
	countUpPayableAmount();
}

Bill::Bill(string _lastName, string _phoneNumber, double _feePerMinute, double _discount, Time _dialogStartTime, Time _dialogEndTime)
{
	lastName = _lastName;
	phoneNumber = _phoneNumber;
	feePerMinute = _feePerMinute;

	if (_discount >= 0 && _discount <= 100)
		discount = _discount;

	dialogStartTime = _dialogStartTime;
	dialogEndTime - _dialogEndTime;

	if (_dialogStartTime > _dialogEndTime)
		swap(dialogStartTime, dialogEndTime);

	countUpPayableAmount();
}

string Bill::getLastName()
{
	return lastName;
}

string Bill::getPhoneNumber()
{
	return phoneNumber;
}

double Bill::getFeePerMinute()
{
	return feePerMinute;
}

double Bill::getDiscount()
{
	return discount;
}

Time Bill::getDialogStartTime()
{
	return dialogStartTime;
}

Time Bill::getDialogEndTime()
{
	return dialogEndTime;
}

double Bill::getPayableAmount()
{
	return payableAmount;
}

void Bill::setLastName(string _lastName)
{
	lastName = _lastName;
}

void Bill::setPhoneNumber(string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

void Bill::setFeePerMinute(double _feePerMinute)
{
	feePerMinute = _feePerMinute;
}

void Bill::setDiscount(double _discount)
{
	discount = _discount;
}

void Bill::setDialogStartTime(Time _dialogStartTime)
{
	dialogStartTime = _dialogStartTime;
}

void Bill::setDialogEndTime(Time _dialogEndTime)
{
	dialogEndTime = _dialogEndTime;
}

void Bill::countUpPayableAmount()
{
	payableAmount = feePerMinute * countMinutes() * (1 - discount);
}

double Bill::countMinutes()
{
	return ((dialogEndTime - dialogStartTime).toMinutes());
}

string Bill::toString()
{
	return "Last name: " + lastName + "\nPhone number: " + phoneNumber + "\nFee per minute" + to_string(feePerMinute) + 
		"Dialog begins at " + dialogStartTime.toString() + "Dialog ends at " + dialogEndTime.toString() + "Payable amount: " + to_string(payableAmount);
}
