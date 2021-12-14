//
//  money.hpp
//  inheritance
//
//  Created by Maxim Chernyshov on 23.11.2021.
//

#include "pair.hpp"

class Money:public Pair
{
public:
    Money(int rub, int cop):Pair(rub, cop){};
    Money(){};
    Money(const Money& obj):Pair(obj){};
    Money operator/(int val);
    int operator/(const Money& obj);
    void norm();
    
    void print()
    {
    }

    friend std::ostream& operator << (std::ostream& out, Money obj);
};
