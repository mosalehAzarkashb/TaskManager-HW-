#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string.h>
#include<vector>

#include"Time.h"
#include"Task.h"



using namespace std;


class Task;

class Employee
{
public:
    Employee(string , string , Time, Time );
    void setName(string);
    void setStartWorktime(Time);
    void setEndWorktime(Time);
    void setWorktime();
    void setSsn(string);

    string getName() const;
    string getSsn() const;
    Time getStartWorktime()const;
    Time getEndWorktime() const ;
    Time getWorktime() const;

    void assignTaskIn(Task&) ;

    vector<Task> getMyTasks() const;


private:
    string name;
    string ssn;
    Time startWorkTime;
    Time endWorkTime;
    Time workTime;
    vector<Task> myTasks;

};

#endif // EMPLOYEE_H_INCLUDED
