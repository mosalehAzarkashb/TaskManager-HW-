#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class Date
{

    friend ostream& operator<<(ostream & , Date &);
    friend istream &operator>> (istream& , Date& );


public:
    explicit Date(unsigned int = 1, unsigned int = 1);

    void setMonth(unsigned int);
    void setDay(unsigned int);

    unsigned int getMonth() const;
    unsigned int getDay() const;


private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool checkDay(unsigned int) const;
};

#endif // DATE_H_INCLUDED
