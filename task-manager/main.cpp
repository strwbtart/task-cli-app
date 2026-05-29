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

            completeTask(tasks);
        }
        else if(choice == 4){

          deleteTask(tasks);
        }
        else if(choice == 5){

            editTask(tasks);
        }
        else if(choice == 6){

            saveTasks(tasks);
        }
        else if(choice == 7){
            cout << "Exiting..." << endl;
            break;
        }
        else{

            cout << "Invalid option." << endl;
        }

        cout << endl;
    }

    return 0;
}