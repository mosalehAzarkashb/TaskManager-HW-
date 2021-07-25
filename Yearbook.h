#ifndef YEARBOOK_H_INCLUDED
#define YEARBOOK_H_INCLUDED

#include"Month.h"



class Yearbook
{

public:
    Yearbook(const unsigned int &y)
    {
        months = new Month[12];
        numOfYear = y;
    }

    Month& getMonth(int index) const
    {
        return months[index];
    }

    ~Yearbook()
    {
     //   delete months;
    }

    int numOfYear;



private:
    Month *months;
};


#endif // YEARBOOK_H_INCLUDED
