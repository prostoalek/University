#include "money.hpp"
#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");

    Money a(35, 60);
    Money b(15,80);

    Pair* p = new Money;
    *p = a + b;
    cout << "*Pair: " << *p;
    Money* q = dynamic_cast<Money*>(p);

    if (q)
    {
     cout << "   До: " << *q;
     q->norm();
     std::cout << "После: " << *q;
    }
    else cout << "Объект не является объектом класса Money\n";
 
    //cout << a << "\n" << b;
    // Money* q = (Money*)p;
    
}
