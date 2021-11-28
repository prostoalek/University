#ifndef Date_H
#define Dete_H
#endif // !Date_H

#include <iostream>
#include <string>
class Date {
private:
    unsigned int year, month, day, currentYear = 2021;


public:
    Date();

    Date(std::string date);


    Date(unsigned int year, unsigned int month, unsigned int day);

    void Display();

    void Read();
    unsigned int Stazh();
};
