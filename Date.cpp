#include "Date.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;



Date::Date( unsigned int m, unsigned int d)
{
    setMonth(m);
    setDay(d);
    year = 2021;
}

void Date::setMonth(unsigned int m)
{
    if(m >= 1 && m <= 12)
        month = m;
    else
        throw std::invalid_argument("Invalid month!");
}

unsigned int Date::getMonth() const
{
    return month;
}

void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        day = d;
    else
        throw std::invalid_argument("Invalid day for current month and year!");
}

unsigned int Date::getDay() const
{
    return day;
}



bool Date::checkDay(unsigned int testDay) const
{
    unsigned int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(testDay <= daysPerMonth[month])
        return true;
    if((month == 2 && testDay == 29) &&
       (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return true;
    return false;
}



ostream& operator<<(ostream &out , Date &d)
{
      out << setfill('0')
              << setw(2) << d.getDay() << "-"
              << setw(2) << d.getMonth() ;
              return out;
}

istream &operator>> (istream& in, Date& d)
{
    in >> setw(2)>>d.day;
    in.ignore();
    in >> setw(2)>>d.month;
}



