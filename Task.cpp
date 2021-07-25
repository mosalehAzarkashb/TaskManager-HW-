#include <iostream>
#include <iomanip>
#include<string.h>

#include "Task.h"
#include "Time.h"

#include <charconv>


using namespace std;

Task::Task(){;};

void Task::setSsnOfDoer(string s)
{
    ssnOfDoer = s;
}

void Task::setDuration(Time t1, Time t2)
{
    duration = t2 - t1;
};

string Task::getSsnOfDoer() const
{
    return ssnOfDoer;
}


string Task::getTitle() const
{
     return title;
}
Time Task::getStart() const
{
    return startTime;
}
Time Task::getEnd() const
{
     return endTime;
}
Date Task::getDate() const
{
    return taskDate;
}
Time Task::getDuration() const
{
    return duration;
}

bool Task::operator> (Task &t2)
{
    if(this->getStart() == t2.getStart())
        return getEnd() > t2.getEnd();
    return getStart() > t2.getStart();
};


bool Task::operator< (Task &t2)
{
    if(this->getStart() == t2.getStart())
        return getEnd() <t2.getEnd();
    return getStart() < t2.getStart();
};
Task Task::operator=(const string &s)
{
    int i =1;
    string t ="";
    while(s[i] != '"')
    {
        t += s[i];
        i++;
    }
    title = t;
    i += 2;
    t = s[i];
    i++;
    t += s[i];
   // cout << t;
    taskDate.setDay(stoi(t));
    i += 2;
    t = s[i];
    i++;
    t += s[i];
   // cout << t;
    taskDate.setMonth(stoi(t));
    i += 3;
    t = s[i];
    i++;
    t += s[i];
   // cout << t;
    startTime.setHour(stoi(t));
    i +=2;
    t = s[i];
    i++;
    t += s[i];
  //  cout << t;
    startTime.setMinute(stoi(t));
    i += 2;
    t = s[i];
    i++;
    t += s[i];
   // cout << t;
    endTime.setHour(stoi(t));
    i += 2;
    t = s[i];
    i++;
    t += s[i];
   // cout << t;
    endTime.setMinute(stoi(t));
    i += 3;
    t = "";
    for(int o = 0 ; o< 8; o++)
        t += s[i];
//    cout << t;
    ssnOfDoer = t;
    return *this;
};
/*
void Task::operator=(string s)
{

    char num_char[3];

    to_chars(num_char, num_char + 2, startTime.getHour());


}*/
string Task::to_string(const unsigned int &d)
{
    stringstream ss;
    ss << setfill('0') <<setw(2)<< d;
    string str = ss.str();
    return str;
}

Task::operator string()
{

        return "\""+title +"\" "
             + to_string(taskDate.getDay())   + "-"
             + to_string(taskDate.getMonth())+ " ["
             + to_string(startTime.getHour())+":"+to_string(startTime.getMinute()) + "-"
             + to_string(endTime.getHour())+":"+to_string(endTime.getMinute())  + "] "
             + ssnOfDoer ;
}

ostream &operator<<(ostream &out , Task &t)
{
            cout << "\"" << t.getTitle() <<"\"  "  ;
            cout << setfill('0')
              << setw(2) << t.getDate().getDay() << "-"
              << setw(2) << t.getDate().getMonth()  <<" [" ;

            cout<< setfill('0')
              << setw(2) << t.getStart().getHour() << ":"
             << setw(2) << t.getStart().getMinute()  <<" - " ;


            cout<< setfill('0')
              << setw(2) << t.getEnd().getHour() << ":"
             << setw(2) << t.getEnd().getMinute()
             << "] " <<t.getSsnOfDoer() <<endl;
             return out;
}








