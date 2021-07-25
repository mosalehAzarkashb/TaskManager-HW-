#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include<string>
#include "Time.h"
#include"Date.h"
#include"Employee.h"
#include"Task.h"

using namespace std;



class Task
{
    friend ostream &operator<<(ostream &out , Task &t);


public:
    Task();
    Task(const string &s , const Time &t1, const Time &t2,  const Date &d)
    : title(s), startTime(t1), endTime(t2), taskDate(d)
    {
         setDuration(t1, t2);
         ssnOfDoer ="11111111";
    };


     operator string();



    string getTitle()const;
    Time getStart()const;
    Time getEnd()const;
    Date getDate()const;
    Time getDuration()const;
    string getSsnOfDoer()const;

    void setDuration(Time, Time );
    void setSsnOfDoer(string);

    bool operator> (Task &);
    bool operator< (Task &);
    Task operator=(const string &);

    string to_string(const unsigned int &d);



private:
    string title;
    Time startTime;
    Time endTime;
    Date taskDate;
    Time duration;
    string ssnOfDoer;
};

#endif // TASK_H_INCLUDED
