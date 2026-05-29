#include "task.h"

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

using namespace std;

// displays menu options
void showMenu(){

    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Complete Task" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Edit Task" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
}

// adds a new task to the vector
void addTask(vector<Task>& tasks){ // pass vector by reference so that changes persist outside the function

    Task newTask; // create new task object

    cout << "Enter task title: " << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer to avoid issues with getline after cin

    getline(cin, newTask.title); // read entire line for task title, allowing for spaces

    newTask.completed = false; // new tasks are not completed by default

    tasks.push_back(newTask); // add new task to vector
    saveTasks(tasks); // save tasks after adding a new task to update the file

    cout << "Task added successfully." << endl;
}

// displays all tasks
void viewTasks(const vector<Task>& tasks){ 

    cout << "Tasks:" << endl;

    if(tasks.empty()){

        cout << "No tasks available." << endl;
    }
    else{

        for(size_t i = 0; i < tasks.size(); i++){

            cout << "[" << i + 1 << "] " << tasks[i].title; // display task number and title, i + 1 because we want to display task numbers starting from 1 instead of 0

            if(tasks[i].completed){

                cout << " (Completed)";
            }
            else{

                cout << " (Pending)";
            }

            cout << endl;
        }
    }
}

// marks a task as completed
void completeTask(vector<Task>& tasks){

    if(tasks.empty()){

        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    int taskNumber; // variable to store user input for task number

    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;

    if(taskNumber > 0 && taskNumber <= tasks.size()){ // check if task number is valid (greater than 0 and less than or equal to the number of tasks)

        tasks[taskNumber - 1].completed = true; // mark the specified task as completed, taskNumber - 1 because vector is 0-indexed but we want to display task numbers starting from 1

        cout << "Task marked as completed." << endl;
        saveTasks(tasks); // save tasks after marking a task as completed to update the file
    }
    else{

        cout << "Invalid task number." << endl;
    }
}

// saves tasks to a file
void saveTasks(const vector<Task>& tasks){
    ofstream outFile("tasks.txt"); // opens and creates file for writing

    if(!outFile){
        cout << "Error opening file." << endl;
        return;
    }

    for(size_t i = 0; i < tasks.size(); i++){
        outFile << tasks[i].title << "," << tasks[i].completed << endl; // writes out task title and completion status
    }
    outFile.close(); // closes the file
    cout << "Tasks saved successfully." << endl;
    cout << endl;
}

// restores tasks from a file whenever program restarts, so that tasks are not lost when program is closed
void loadTasks(vector<Task>& tasks){
    ifstream inFile("tasks.txt"); // opens file to read, read FROM file
    
    if(!inFile){
        return;
    }

    string line;

    while(getline(inFile, line)){ // read one line at a time until file ends
        size_t commaPos = line.find(','); // find position of comma
        if(commaPos == string::npos){
            continue;
        }

        string title = line.substr(0, commaPos); // substr (start, length), start at index 0 and grab everything before comma
        
        string completedStr = line.substr(commaPos + 1); // grab everything after comma

        bool completed = (completedStr == "1"); // convert string to bool so that "1" becomes true and "0" becomes false
        // true = 1 = completed, false = 0 = not completed

        Task loadedTask;
        loadedTask.title = title;
        loadedTask.completed = completed;

        tasks.push_back(loadedTask); // add loaded task to vector
        cout << "Tasks loaded successfully." << endl;
        cout << endl;

    }
}

void deleteTask(vector<Task>& tasks){
        if(tasks.empty()){
            cout << "No tasks available to delete." << endl;
            return;
        }

        int taskNumber;
        cout << "Enter the number of the task to delete: ";
        cin >> taskNumber;

        if(taskNumber > 0 && taskNumber <= tasks.size()){
            tasks.erase(tasks.begin() + taskNumber - 1); //taskNumber - 1 because vector is 0-indexed but we want to display task numbers starting from 1
            saveTasks(tasks); // save tasks after deletion to update the file
            cout << "Task deleted successfully." << endl;
        }
        else{
            cout << "Invalid task number." << endl;
        }
    }

void editTask(vector<Task>& tasks){
    if(tasks.empty()){
        cout << "No tasks available to edit." << endl;
        return;
    }
        int taskNumber;
        cout << "Enter the number of the task to edit: ";
        cin >> taskNumber;
        if(taskNumber > 0 && taskNumber <= tasks.size()){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string newTitle;
            cout << "Enter the new title for the task: ";
            getline(cin, newTitle);
            tasks[taskNumber -1].title = newTitle; // makes sure vector starts at 0 but task number 1
            saveTasks(tasks);
            cout << "Task updated successfully." << endl;
        }
        else{
            cout << "Invalid task number." << endl;
        }
    }

