#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;


Time::Time()
    : hour(0), minute(0) {}

Time::Time(unsigned int h, unsigned int m)
{
    setTime(h, m);
}

void Time::setTime(unsigned int h, unsigned int m)
{
    setHour(h);
    setMinute(m);
}

void Time::setHour(unsigned int h)
{
    if(h < 0 || h >= 24)
        hour = 0;
    else
        hour = h;
}

unsigned int Time::getHour() const
{
    return hour;
}

void Time::setMinute(unsigned int m)
{
    if(m < 0 || m >= 60)
        minute = 0;
    else
        minute = m;
}

unsigned int Time::getMinute() const
{
    return minute;
}


    bool Time::operator< (Time t2) const
    {
        if(this->getHour() == t2.getHour())
            return getMinute() < t2.getMinute();
        return getHour() < t2.getHour();
    };


    bool Time::operator> (Time t2) const
    {
        if(this->getHour() == t2.getHour())
            return getMinute() > t2.getMinute();
        return getHour() > t2.getHour();
    };


    Time Time::operator+(int p) const
    {
        Time temp = *this;
        temp.minute += p;
        if(temp.minute > 60)
        {
            temp.hour++;
            temp.minute -= 60;
        }
        return temp;
    };

    Time Time::operator+(Time t) const
    {
        Time temp = *this;
        temp += t.minute;

        temp.hour = temp.hour + t.hour;

        return temp;
    };

    Time& Time::operator+=( int p)
    {
        minute += p;
        if(minute > 60)
        {
            hour++;
            minute -= 60;
        }
        return *this;
    }
    Time Time::operator- (int p) const
    {
        Time temp = *this;
        int min = temp.minute;
        min -= p ;
        if(min < 0)
        {
            min  += 60;
            temp.hour--;
        }
        temp.minute = min;

        return temp;
    }

    Time Time::operator-(Time t) const
    {
        if(t > *this)
            {
                Time tt(0 , 0);
                return tt;
            }

        Time temp = *this;
        temp = temp - t.minute;
        temp.hour = temp.hour - t.hour;
        return temp;
    }

    bool Time::operator==(Time t) const
    {
        Time temp = *this;
        if(temp.getHour() == t.getHour() && temp.getMinute() == t.getMinute())
            return true;
        return false;
    }



ostream& operator<<(ostream &out , Time &t)
{
      out << setfill('0')
              << setw(2) << t.getHour() << ":"
              << setw(2) << t.getMinute() ;
              return out;
}

istream &operator>> (istream& in, Time& t)
{
    in >> setw(2)>>t.hour;
    in.ignore();
    in >> setw(2)>>t.minute;
}

