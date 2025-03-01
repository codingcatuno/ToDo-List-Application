#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <string>
#include "ToDoListing.h"

using namespace std;

/*
 *
 * Devloper comments
 * -----------------
 *  Everything looks good, probably gonna be updates in the future but for now just
 *   make sure to add comment to things especially the functions so its readable to not only you
 *   but also others who will use your code. :)

 *   02/19/2025: Work to do is to comment everything then after that commit it to GitHub then
 *   finish working on the README. After that this project will be completed

 *   From there make sure that you work on the other projects while completing the course
 *   (in respects to what you know and don't know).
 */ 

int main() {
    int userIntInput;
    string userStrInput;
    string currentFile;
    TaskManager mainFileCtrl;
    FileManager manager;

    cout
            << "Welcome to the To-Do Application by Cyril D. Tchouta-Moussa with the help of Documentation and Stack Overflow\n";
    cout
            << "                                     !Read the README File for Instructions!                                             \n";
    cout
            << "----------------------------------------------------------------------------------------------------------------\n"
            << endl;
    system("Pause");
    logclear();

    // Start Menu
    while (userIntInput != 5) {
        cout << "Select ONE of the options below using the SPECIFIED number! " << endl
             << "-------------------------------------------------------------------" << endl;
        manager.print();
        cout << "--------------------------------------" << endl;
        cout << "Option 1: Open/Add a File\n"
             << "Option 2: Delete File\n"
             << "*COMING SOON* Option 3: EDIT\n"
                "Option 5: Quit\n\n";
        cout << "Option: ";
        cin >> userIntInput;
        while (userIntInput < 1 || userIntInput > 5 || userIntInput == 3 || userIntInput == 4 || userIntInput == cin.fail()){
            logclear();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Select ONE of the options below using the SPECIFIED number! " << endl
                 << "-------------------------------------------------------------------" << endl;
            manager.print();
            cout << "--------------------------------------" << endl;
            cout << "Option 1: Open a File\n"
                 << "Option 2: Delete File\n"
                 << "*COMING SOON* Option 3: EDIT\n"
                    "Option 5: Quit\n\n";
            cout << "Invalid Option. Please retry!\n";
            cout << "Option: ";
            cin >> userIntInput;
        }
        switch (userIntInput) {
            // File entry or File Creation
            case 1: {
                userIntInput = 0;

                logclear();
                cout << "Type the File name IDENTICAL to how is showen or Type in a NEW file name ending with \".json\""
                     << endl;
                cout << "Which file would you like to open!" << endl;
                cout << "----------------------------------------------------------------------------------------------"
                     << endl;
                manager.print();
                cout << "File: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> userStrInput;
                while (userStrInput.size() <= 5 || userStrInput.compare(userStrInput.size()-5,5,".json") != 0){
                    cin.clear();
                    logclear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Type the File name IDENTICAL to how is showen or Type in a NEW file name ending with \".json\""
                         << endl;
                    cout << "Which file would you like to open!" << endl;
                    cout << "----------------------------------------------------------------------------------------------"
                         << endl;
                    manager.print();
                    cout << "Invalid File name. Please retry!\n";
                    cout << "File: ";
                    cin >> userStrInput;
                }

                logclear();
                manager.fileNameUpdate(mainFileCtrl, userStrInput);
                while (userIntInput != 5) {
                    cout << "Select ONE of the options below using the SPECIFIED number! " << endl;
                    cout
                            << "----------------------------------------------------------------------------------------------"
                            << endl;
                    mainFileCtrl.listTasksByPriority();
                    cout << "Option 1: Add new task\n"
                         << "Option 2: Edit task\n"
                         << "Option 3: Delete SPECIFIC task\n"
                         << "Option 4: Delete ALL tasks\n"
                         << "Option 5: Back\n\n";

                    cout << "Option: ";
                    cin >> userIntInput;

                    while (userIntInput < 1 || userIntInput > 5 || userIntInput == cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Select ONE of the options below using the SPECIFIED number! " << endl;
                        cout
                                << "----------------------------------------------------------------------------------------------"
                                << endl;
                        mainFileCtrl.listTasksByPriority();
                        cout << "Option 1: Add new task\n"
                             << "Option 2: Edit task\n"
                             << "Option 3: Delete SPECIFIC task\n"
                             << "Option 4: Delete ALL tasks\n"
                             << "Option 5: Back\n\n";
                        cout << "Invalid Option. Please retry!\n";
                        cout << "Option: ";
                        cin >> userIntInput;
                    }
                    switch (userIntInput) {
                        // Add Task
                        case 1: {
                            userIntInput = 0;
                            string addTask;
                            int addPriority;
                            string configaddPriority;
                            string addDueDate;

                            logclear();

                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Enter your Task: ";
                            getline(cin, addTask);
                            logclear();
                            cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
                            cout << "Select your Priority (1 | 2 | 3): ";
                            cin >> addPriority;
                            while (addPriority == cin.fail() || addPriority < 1 || addPriority > 3) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                logclear();
                                cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
                                cout << "Invalid Option. Please retry!\n";
                                cout << "Select your Priority (1 | 2 | 3): ";
                                cin >> addPriority;
                            }
                            if (addPriority == 3) {
                                configaddPriority = "High";
                            } else if (addPriority == 2) {
                                configaddPriority = "Medium";
                            } else if (addPriority == 1) {
                                configaddPriority = "Low";
                            }
                            logclear();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "Enter your Due Date in any order you'd like: ";
                            getline(cin,addDueDate);
                            logclear();
                            mainFileCtrl.addTask(addTask, configaddPriority, addDueDate);
                            break;
                        }
                        // Edit Task
                        case 2: { // Use similar logic to case 1 but great work was done u got this! :)
                            userIntInput = 0;
                            string oldTask;
                            string editTask;
                            int editPriority;
                            string configeditPriority;
                            string editDueDate;

                            logclear();

                            if (mainFileCtrl.checkEmpty()){
                                cout << "No tasks to edit!" << endl;
                                break;
                            }
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            mainFileCtrl.listTasksByPriority();
                            cout << "----------------------------------------------------------------------------------------------" << endl;
                            cout << "Type the Task you'd like to edit Identically: ";
                            getline(cin, oldTask);

                            if (!mainFileCtrl.checkFoundTask(oldTask)){
                                logclear();
                                cout << "Task not Found! :/" << endl;
                                break;
                            }

                            logclear();

                            cout << "Enter your Task: ";
                            getline(cin, editTask);
                            logclear();
                            cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
                            cout << "Select your Priority (1 | 2 | 3): ";
                            cin >> editPriority;
                           while (editPriority == cin.fail() || editPriority < 1 || editPriority > 3) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                logclear();
                                cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
                                cout << "Invalid Option. Please retry!\n";
                                cout << "Select your Priority (1 | 2 | 3): ";
                                cin >> editPriority;
                            }
                            if (editPriority == 3) {
                                configeditPriority = "High";
                            } else if (editPriority == 2) {
                                configeditPriority = "Medium";
                            } else if (editPriority == 1) {
                                configeditPriority = "Low";
                            }
                            logclear();
                            cout << "Enter your Due Date in any order you'd like: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            getline(cin,editDueDate);
                            logclear();
                            mainFileCtrl.edit(oldTask, editTask, configeditPriority, editDueDate);
                            break;
                        }
                        // Delete Task
                        case 3: {
                            userIntInput = 0;
                            string deleteTask;
                            logclear();

                            if (mainFileCtrl.checkEmpty()){
                                cout << "No tasks to delete :/" << endl;
                                break;
                            }

                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "WARNING DELETING TASK!" << endl;
                            cout << "Type the Task you'd like to delete Identically: " << endl;
                            cout << "----------------------------------------------------------------------------------------------" << endl;
                            mainFileCtrl.listTasksByPriority();
                            getline(cin, deleteTask);

                            if (!mainFileCtrl.checkFoundTask(deleteTask)){
                                logclear();
                                cout << "Task not Found! :/" << endl;
                                break;
                            }

                            logclear();
                            mainFileCtrl.deleteTaskByName(deleteTask);
                            break;
                        }
                        // Delete ALL tasks
                        case 4: {
                            userIntInput = 0;
                            logclear();
                            mainFileCtrl.deleteAllTasks();

                            break;
                        }
                        // Back
                        case 5: {
                            logclear();
                            break;
                        }
                    }
                }
                userIntInput = 0;
                break;
            }
            // Delete File
            case 2: {
                userIntInput = 0;

                logclear();
                cout << "WARNING DELETING TASK!" << endl;
                cout << "Type the File name IDENTICAL to how is showen" << endl;
                cout << "----------------------------------------------------------------------------------------------" << endl;
                manager.print();
                cout << "File: ";
                cin >> userStrInput;
                while (userStrInput.size() <= 5 || userStrInput.compare(userStrInput.size()-5,5,".json") != 0){
                    cin.clear();
                    logclear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Type the File name IDENTICAL to how is showen" << endl;
                    cout << "----------------------------------------------------------------------------------------------"
                         << endl;
                    manager.print();
                    cout << "Invalid File name. Please retry!\n";
                    cout << "File: ";
                    cin >> userStrInput;
                }
                logclear();
                manager.deleteFile(userStrInput);
                break;
            }
            // Quit
            case 5: {
                logclear();
                break;
            }
        }
    }
    cout << "Thank you for using my To-Do List Application! :)" << endl;
    return 0;
}
