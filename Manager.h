#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED


#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include<algorithm>
#include<vector>
#include<exception>
#include<fstream>
#include "Time.h"
#include "Task.h"
#include"Month.h"
#include"Day.h"
#include"Date.h"
#include"Yearbook.h"
#include "Employee.h"
using namespace std;


Yearbook yb(2021);


class Manager
{
public:

void Now()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout <<setfill('0') << setw(2)
              << setw(2)<< ltm->tm_mday << "-"
              << setw(2)<< ltm->tm_mon +1 <<"  "
              << setw(2)<< ltm->tm_hour<<":"
              << setw(2)<< ltm->tm_min << endl;
}

void addTask(const Task &t)
{
    yb.getMonth(t.getDate().getMonth()).getDay(t.getDate().getDay()).addTaskToDay(t);
    cout << "task added successfully" <<endl;
}


void today( )
{
        time_t now = time(0);
        tm *ltm = localtime(&now);

        yb.getMonth(ltm-> tm_mon +1).getDay(ltm->tm_mday).printTasks();
}

void monthTasks()
{
        time_t now = time(0);
        tm *ltm = localtime(&now);

        yb.getMonth(ltm-> tm_mon +1).showTasks();
}


void free(Date d, Time t)
{
    vector<Task> &v = yb.getMonth(d.getMonth()).getDay(d.getDay()).getTasks() ;

    for(int i = 0 ; i < v.size(); i++)

        if(v[i].getStart() < t && v[i].getEnd() > t)
             v.erase(v.begin()+i);

    if(v[v.size()-1].getStart() < t && v[v.size()-1] .getEnd() > t)
        v.erase(v.begin()+v.size()-1);
    cout << "tasks deleted successfully" <<endl;
}

bool  findtime(const Time &t)
{
    time_t n = time(0);
    tm *ltm = localtime(&n);
    Time now(ltm->tm_hour,ltm->tm_min);

    vector<Task> &v = yb.getMonth(ltm->tm_mon+1).getDay(ltm->tm_mday).getTasks();
    sort(v.begin(), v.end());


    for(int i = 0; i < v.size();i++)
    {
        if(now > v[i].getEnd())
            continue;
        if((now+t) < v[i].getStart())
        {
            Time end = now +t;
            cout <<"[";
            cout<< now ;
            cout<< " - ";
            cout<< end;
            cout <<"]" << endl;
            return true;
        }
        else
            now = v[i].getEnd();
    }
            Time end = now +t;
            cout <<"[";
            cout<< now ;
            cout<< " - ";
            cout<< end;
            cout <<"]" << endl;
            return true;

};

void addEmployee(const Employee &e)
{
    employees.push_back(e);
    cout << "employee added successfully" <<endl;
}



void assignTaskOut(const string &ssn,const string &name)
{
    time_t n = time(0);
    tm *ltm = localtime(&n);
    vector<Task> &v = yb.getMonth(ltm->tm_mon+1).getDay(ltm->tm_mday).getTasks();
    int i;
    for( i = 0; i < v.size() ;i++)
        if(v[i].getTitle() == name)
            break;

    for (int o = 0; i < employees.size();o++)
        if(employees[o].getSsn() == ssn)
            {
                employees[o].assignTaskIn(v[i]);
                break;
            }

}

void schedule(string ssn, Date d)
{
    int i;
    for(i = 0; i < employees.size() ;i++)
        if(employees[i].getSsn() == ssn)
            break;
    employees[i].getMyTasks().clear();
    Employee &e = employees[i];


    vector<Task> &v = yb.getMonth(d.getMonth()).getDay(d.getDay()).getTasks();
    vector<Time> durations;
    for(int i = 0; i < v.size() ;i++)
        if(v[i].getStart() > e.getStartWorktime() && v[i].getEnd() < e.getEndWorktime())
            durations.push_back(v[i].getDuration());
        else
            continue;

    sort(durations.rbegin(), durations.rend());
    Time temp =employees[i].getWorktime();
    for (auto it = durations.rbegin(); it != durations.rend(); ++it)
    {
      //  cout << *it;
    //    cout << "------";
        if(temp < *it || *it ==*(it-1))
            continue;

        for(int o = 0; o < v.size() ; o++)
            //Time * p;
         //   Time &m = p;
      //      m = v[o].getDuration();
            if(*it ==  v[o].getDuration() && temp >*it )
            {
   //             Time ttt =v[o].getDuration();
   //             cout << ttt;
  //              cout << *it;
                employees[i].getMyTasks().push_back(v[o]);
                cout << endl;
                cout << v[o];
                temp = temp - v[o].getDuration();
            }
    }
}

void exit()
{
    fstream fileTasks("dataOfTasks", ios::binary  | ios::out);
    if(!fileTasks)
        cout << "Error in file!" << endl;
    time_t n = time(0);
    tm *ltm = localtime(&n);
    vector<Task> &t = yb.getMonth(ltm->tm_mon+1).getDay(ltm->tm_mday).getTasks();
  //  Task &p =  t[0];
    string k ; //p.to_string();
    long pos = fileTasks.tellp();
    for (int i = 0;i < t.size();i++)
    {
        k = t[i];
        fileTasks.seekp(pos, ios::beg);
        fileTasks.write(reinterpret_cast<char*>(&k[0]) , sizeof(k));
        pos = fileTasks.tellp();
    }
    fileTasks.close();

/*
    fstream fileEmployee("dataOfEmployee", ios::binary  | ios::out);
    if(!fileEmployee)
        cout << "Error in file!" << endl;
//    time_t n = time(0);
//    tm *ltm = localtime(&n);
    vector<Employee> &e = employees ;
  //  Task &p =  e[0];
    string g ; //p.to_string();
    long poss = fileEmployee.tellp();
    for (int i = 0;i < t.size();i++)
    {
        g = e[i];
        fileEmployee.seekp(poss, ios::beg);
        fileEmployee.write(reinterpret_cast<char*>
                   (&g[0]) , sizeof(g));
        poss = fileEmployee.tellp();
    }
    fileEmployee.close();

*/
    cout << "nice to meet you" <<endl << "good bye.";
}



private:
    vector<Employee> employees;

};




#endif // MANAGER_H_INCLUDED
