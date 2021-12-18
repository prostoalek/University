#include<iostream>
#include "Bill.h"

using namespace std;

int main() {

	Bill Vladimir("Visotskiy", "+790080330808", 3.5, 5, Time("16:00:00"), Time(16, 11, 19));
	Bill Arkadiy("Figurist", "89206544444", 4.5, 10, Time(14, 11, 31), Time("12:20:29"));

	cout << Vladimir.toString() << "\n\n" << Arkadiy.toString() << "\n\n";

	Vladimir.setFeePerMinute(1);
	Vladimir.setDialogStartTime(Vladimir.getDialogEndTime());
	Arkadiy.setDiscount(Arkadiy.getDiscount() + 10);

	cout << Vladimir.toString() << "\n\n" << Arkadiy.toString() << "\n";


}