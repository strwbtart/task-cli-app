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
    cout << "3. Exit" << endl;
    cout << "4. Mark task as completed" << endl;
    cout << "5. Save Tasks" << endl;
}

// adds a new task to the vector
void addTask(vector<Task>& tasks){

    Task newTask;

    cout << "Enter task title: " << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, newTask.title);

    newTask.completed = false;

    tasks.push_back(newTask);

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

            cout << i + 1 << ". " << tasks[i].title;

            if(tasks[i].completed){

                cout << " (Completed)";
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

    int taskNumber;

    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;

    if(taskNumber > 0 && taskNumber <= tasks.size()){

        tasks[taskNumber - 1].completed = true;

        cout << "Task marked as completed." << endl;
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

    }
}