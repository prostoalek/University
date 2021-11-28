#include <iostream>
#include <string>
//#include "Date.h"
#include "Payment.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    Payment max;
    max.read();
    max.vichisl_nach_summ();
    max.vichisl_yder_summ();
    max.vichisl_zp();
    max.Display();
    max.stazh();

}