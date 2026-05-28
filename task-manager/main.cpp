#include <iostream>
#include "task.h"

using namespace std;

int main(){

    vector<Task> tasks;

    loadTasks(tasks); 

    while(true){

        showMenu();

        int choice;
        cin >> choice;

        cout << endl;

        if(choice == 1){
            addTask(tasks);
        }
        else if(choice == 2){
            viewTasks(tasks);
        }
        else if(choice == 3){
            saveTasks(tasks); 
            cout << "Exiting..." << endl;
            break;
        }
        else if(choice == 4){
            completeTask(tasks);
        }
        else{
            cout << "Invalid option." << endl;
        }

        cout << endl;
    }

    return 0;
}