#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include<exception>
using namespace std;

class Time
{
    friend std::ostream &operator<< (std::ostream& , Time&) ;
    friend std::istream &operator>> (std::istream& , Time&) ;


public:
    Time();
    Time(unsigned int, unsigned int);

    void setTime(unsigned int, unsigned int);
    void setHour(unsigned int);
    void setMinute(unsigned int) ;

    unsigned int getHour() const;
    unsigned int getMinute() const;

    bool operator< (Time )const;
    bool operator> (Time ) const;

    Time operator+(int ) const;
    Time operator+(Time ) const;
    Time& operator+=( int ) ;

    Time operator- (int ) const;
    Time operator-(Time ) const;

    bool operator==(Time ) const;


private:
    unsigned int hour;
    unsigned int minute;
};

#endif // TIME_H_INCLUDED
