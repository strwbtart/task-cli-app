#ifndef TASK_H // Only include this file ONCE. 
#define TASK_H

#include <string>
#include <vector>

using namespace std;

struct Task{
    string title;
    bool completed;
};

void showMenu();

void addTask(vector<Task>& tasks);

void viewTasks(const vector<Task>& tasks);

void completeTask(vector<Task>& tasks);

void saveTasks(const vector<Task>& tasks);

void loadTasks(vector<Task>& tasks);

void deleteTask(vector<Task>& tasks);

#endif