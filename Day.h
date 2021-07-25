#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED

#include <vector>
#include"Task.h"
#include "Time.h"

using namespace std;



class Day
{
public:
    Day():numberOfTasks(0) {   }
    void addTaskToDay(const Task &t)
    {
        tasks.push_back(t);
    }

     void printTasks()
    {
        for (int i = 0; i < tasks.size(); i++)
            cout <<"("<< i+1<<")    "<<tasks[i];
    }

    vector<Task>& getTasks()
    {
        return tasks;
    }


private:
    vector<Task>  tasks;
    int numberOfTasks;
};

#endif // DAY_H_INCLUDED
