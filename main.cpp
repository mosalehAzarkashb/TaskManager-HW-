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
#include"Manager.h"
using namespace std;



int main()
{
    Manager m1;
// if you have a file that includes Tasks uncomment below.

    fstream file("dataOfTasks", ios::binary  | ios::in);
    char j[100] ;
    file.seekp(0, ios::beg);
    long pos = file.tellp() ;
    if(file)
    {
        while(!file.eof())
        {
            file.seekp(pos, ios::beg);
            file.read(reinterpret_cast<char*>(&j) , 32);
          //  cout << j << endl;
            Task t ;
             t = j;

             m1.addTask(t);

            pos = file.tellp();
         }


         file.close();
    }






/* test
    Date d1(7,17);
    Time t1(18,20);
    Time t2(20,20);
Task t("ss",t1,t2,d1);


t = j;
cout << t << endl;



cout <<s;
string s = t.to_string();
cout << s;

file.write(reinterpret_cast<char*>(&s) , sizeof(s));

file.read(reinterpret_cast<char*>(&j) , sizeof(j));
cout << j;
file.close();

*/




while (true)
{

    string input;
    getline(cin, input);

     if(input == "add task")
        {
                string title;
                Date d;
                Time t1;
                Time t2;
               cin.ignore(9);
               cin >> setw(20) >> title;
               cin.ignore(10);
               cin >> d;
               cin.ignore();
               cin >> t1;
               cin.ignore(14);
               cin >> t2;
               Task t(title,t1,t2,d);
               cin.ignore(4);
               m1.addTask(t);

        }
        else if(input == "add employee")
        {
            string n;
            string ssn;
            Time s;
            Time e;
            cin.ignore(9);
            getline(cin , n);
            cin.ignore(8);
            getline(cin, ssn);
            cin.ignore(9);
            cin >> s;
            cin.ignore(8);
            cin >> e;
            cin.ignore(4);

            Employee emp(n,ssn,s,e);
            m1.addEmployee(emp);
        }

    else if(input == "today")
    {
        m1.today();
    }
    else if (input == "month")
    {
        m1.monthTasks();
    }
    else if(input == "free")
    {
        Date d;
        Time t;
        cin >> d;
        cin >> t;
        m1.free(d,t);
    }
    else if(input == "now")
    {
        m1.Now();
    }
    else if(input == "find time")
    {
        Time du;
        cin >> du;
        m1.findtime(du);
    }
    else if(input == "assign task")
    {
        string ss, task;
        cin.ignore(7);
        cin >> setw(10) >>ss;
        cin.ignore(9);
        cin >> task;
        cin.ignore(4);


       // cout << ss << "-----" << task;
        m1.assignTaskOut(ss,task);

    }
    else if(input == "schedule")
    {
        Date d;
        string ss;
        cin >> d;
        cout << d;
        cin >>setw(10) >>ss;
        cout << ss;
        m1.schedule(ss,d);
    }
    else if (input == "exit")
    {
        m1.exit();
        break;
    }

};











/*   test
add employee
name is Sobhan
ssid is 0441060994
starts at 9:00
ends at 15:00
done

add task
title is c+
starts at 18-07 13:00
ends at 18-07 14:00
done



*/

/*
    Time t1(18,20);
    Time t2(20,20);
    Time t3(20,20);
    Time t4(21,20);



    cout << t1 <<endl;
    cout << t2 <<endl;
    cout << t3 <<endl;

    Date d1(7,17);
    Date d2(2,19);
    Date d3(2,11);

    cout << d1 <<endl;
    cout << d2<<endl;
    cout << d3<<endl;



    string name = "hi";
    Task t(name, t1 , t4, d1);
    Task tt("ali", t1, t4, d1);
    Task ttt("c+", t1, t2, d1);

 //   yb.getMonth(d1.getMonth()).getDay(d1.getDay()).addTaskToDay(ttt);
    m1.addTask(ttt);
//    yb.getMonth(d1.getMonth()).getDay(d1.getDay()).addTaskToDay(tt);
    m1.addTask(tt);
//    yb.getMonth(d1.getMonth()).getDay(d1.getDay()).addTaskToDay(t);
    m1.addTask(t);


cout << "---------------------------\n";
    m1.monthTasks();
//    yb.getMonth(7).showTasks();
cout << "---------------------------\n";
    m1.today();
    Time freet1(5,10);
    //m1.free(d1,freet1);
cout << "---------------------------\n";
    m1.monthTasks();
cout << "---------------------------\n";
    m1.today();
    Time freet2(21,10);
  //  m1.free(d1,freet2);
cout << "---------------------------\n";
    m1.monthTasks();

cout << "---------------------------\n";
    m1.today();
cout << "---------------------------\n";
    m1.monthTasks();


    m1.Now();
    Time duration(3,50);
    m1.findtime(duration);


    Time t5(5, 2);
    Time t6(22, 2);

    Employee e1("ali","0441060994",t5,t6);
    m1.addEmployee(e1);
     cout << yb.getMonth(7).getDay(17).getTasks()[0];

    m1.assignTaskOut("0441060994","c+");



cout << "\n----------scedule-----------------\n";
    m1.schedule("0441060994", d1);

    /*
    t5 =t.getDuration();
    cout << t5 << endl;
    t5 =tt.getDuration();
    cout << t5 << endl;
    t5 =   t2 - t1;
    cout << t5;


//m1.exit();


cout << "00000000000000000";

string welldone =t.to_string();

cout << welldone;

*/

    return 0;
}
