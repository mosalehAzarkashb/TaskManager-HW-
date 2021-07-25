#ifndef MONTH_H_INCLUDED
#define MONTH_H_INCLUDED

#include"Day.h"

using namespace std;



class Month
{

public:
    Month( )
    {
        days = new Day[31];
    };

    void showTasks() const
    {
        for(int i = 0; i < 31 ; i++)
                (days[i]).printTasks() ;
    };



    Day& getDay(int index) const
    {
        return days[index];
    }

    ~Month()
    {
//        delete days;
    }

private:
    Day *days;

};


#endif // MONTH_H_INCLUDED
