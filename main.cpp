#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "ToDoListing.h"


using namespace std;

int main() {
    /* TaskManager manager("taskfile.json");
    manager.addTask("Buy groceries", "Medium", "2025-01-03");
    manager.addTask("Call cousin", "High", "2025-01-04");
    manager.addTask("Send money to UBER", "Low", "2025-01-04");

    manager.listTasksByPriority();
    manager.edit("Call cousin", "Call Mother", "Low", "2025-01-05");
    manager.listTasksByPriority();
     */

    cout << "Welcome to the To-Do Application by Cyril D. Tchouta-Moussa with A LOT of help" << endl <<
         "----------------------------------------------------------------------------------" << endl;

    FileManager Manager;
    Manager.print();
    //TaskManager file1("test.json");

    //file1.addTask("Clean kitchen", "High", "01-05-2025");
    //file1.listTasksByPriority();
    //file1.deleteAllTasks();
   // file1.listTasksByPriority();
    return 0;
}
