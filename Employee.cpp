#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

Employee::Employee(string nam, string ssn, Time s, Time e)
:name(""), ssn("0000000000"), workTime(0,0)
{
    setName(nam);
    setSsn(ssn);
    setStartWorktime(s);
    setEndWorktime(e);
    setWorktime();

}

void Employee::setName(string s)
{
    name = s;
}
string Employee::getName() const
{
    return name;
}
void Employee::setSsn(string s)
{
    ssn = s;
}
string Employee::getSsn() const
{
    return ssn;
}
void Employee::setStartWorktime(Time n)
{
    startWorkTime = n;
}
Time Employee::getStartWorktime()const
{
    return startWorkTime;
}


void Employee::setEndWorktime(Time n)
{
    endWorkTime = n;
}


Time Employee::getEndWorktime() const
{
    return endWorkTime;
}

void Employee::setWorktime()
{
    workTime = endWorkTime - startWorkTime;
}
Time Employee::getWorktime()  const
{
    return workTime;
}

vector<Task> Employee::getMyTasks() const
{
    return myTasks;
}


void Employee::assignTaskIn( Task &t)
{
    myTasks.push_back(t);
    t.setSsnOfDoer(this->getSsn());
 //   cout << myTasks[myTasks.size()-1];
    cout << "task assigned successfully" <<endl;

}

