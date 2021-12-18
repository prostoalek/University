#include "Bill.h"

void Bill::setPayableAmount(double _payableAmount)
{
	payableAmount = _payableAmount;
}

Bill::Bill()
{
	lastName = "unknown";
	phoneNumber = "unknown";
	feePerMinute = 0;
	discount = 0;
	dialogStartTime = Time();
	dialogEndTime = Time();
	calculatePayableAmount();
}

Bill::Bill(string _lastName, string _phoneNumber, double _feePerMinute, double _discount, Time _dialogStartTime, Time _dialogEndTime)
{
	lastName = _lastName;
	phoneNumber = _phoneNumber;
	feePerMinute = _feePerMinute;

	if (_discount >= 0 && _discount <= 100)
		discount = _discount;

	dialogStartTime = _dialogStartTime;
	dialogEndTime = _dialogEndTime;

	if (_dialogStartTime > _dialogEndTime)
		swap(dialogStartTime, dialogEndTime);

	calculatePayableAmount();
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
	if (_dialogStartTime < dialogEndTime)
		dialogStartTime = _dialogStartTime;
}

void Bill::setDialogEndTime(Time _dialogEndTime)
{
	if (dialogStartTime < _dialogEndTime)
		dialogEndTime = _dialogEndTime;
}

void Bill::calculatePayableAmount()
{
	payableAmount = feePerMinute * dialogDurationInMinutes() * (1 - discount / 100);
}

double Bill::dialogDurationInMinutes()
{
	return ((dialogEndTime - dialogStartTime).toMinutes());
}

string Bill::toString()
{
	return "Last name: " + lastName + "\nPhone number: " + phoneNumber + "\nFee per minute: " + to_string(feePerMinute) + 
		"\nDialog begins at " + dialogStartTime.toString() + "\nDialog ends at " + dialogEndTime.toString() + "\nPayable amount: " + to_string(payableAmount);
}
