#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "ToDoListing.h"

/* TaskManager manager("taskfile.json");
   manager.addTask("Buy groceries", "Medium", "2025-01-03");
   manager.addTask("Call cousin", "High", "2025-01-04");
   manager.addTask("Send money to UBER", "Low", "2025-01-04");

   manager.listTasksByPriority();
   manager.edit("Call cousin", "Call Mother", "Low", "2025-01-05");
   manager.listTasksByPriority();
    */

using namespace std;


int main() {
    int userIntInput;
    string userStrInput;
    string currentFile;
    TaskManager mainFileCtrl;
    FileManager manager;

    cout << "Welcome to the To-Do Application by Cyril D. Tchouta-Moussa with the help of Documentation and Stack Overflow\n";
    cout << "                                     !Read the README File for Instructions!                                             \n";
    cout << "----------------------------------------------------------------------------------------------------------------\n" << endl;
    system("Pause");
    logclear();

    while (userIntInput != 5){

        cout << "Select ONE of the options below using the SPECIFIED number! " << endl
        << "-------------------------------------------------------------------" << endl;
        manager.print();
        cout << "--------------------------------------" << endl;
        cout << "Option 1: Open a File\n"
             << "Option 2: Delete File\n"
             << "*COMING SOON* Option 3: EDIT\n"
                "Option 5: Quit\n\n";
        cout << "Option: "; cin >> userIntInput;
        switch (userIntInput){
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
                cin >> userStrInput;

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
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout << "Option: "; cin >> userIntInput;
                    switch (userIntInput) {
                        case 1: {
                            userIntInput = 0;
                            string addTask;
                            int addPriority;
                            string configaddPriority;
                            string addDueDate;

                            logclear();

                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Enter your Task: ";
                            getline(cin,addTask);
                            logclear();
                            cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
                            cout << "Select your Priority (1 | 2 | 3): ";
                            cin >> addPriority;
                            while (addPriority < 1 || addPriority > 3) {
                                logclear();
                                cout << "Incorrect Option! :/ Please try again!" << endl;
                                cout << "3: HIGH Priority\n2: MEDIUM Priority\n1: LOW Priority\n";
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
                            cout << "Enter your Due Date in any order you'd like: ";
                            cin >> addDueDate;
                            logclear();
                            mainFileCtrl.addTask(addTask, configaddPriority, addDueDate);
                            break;
                        }
                        case 2: { // Use similar logic to case 1 but great work was done u got this! :)
                            userIntInput = 0;
                            logclear();



                            break;
                        }
                        case 3: {
                            userIntInput = 0;
                            logclear();
                            break;
                        }
                        case 4: {
                            userIntInput = 0;
                            logclear();
                            break;
                        }
                        case 5: {
                            logclear();
                            break;
                        }
                    }
                }
                userIntInput = 0;
                break;
            }
            case 2: {
                userIntInput = 0;

                logclear();
                cout << "Type the Identical File name shown below:" << endl;
                cout << "----------------------------------------------------------------------------------------------"
                     << endl;
                manager.print();
                cout << "File: ";
                cin >> userStrInput;

                logclear();
                manager.deleteFile(userStrInput);
                break;
            }
            case 5: {
                logclear();
                break;
            }
        }
        //system("pause");
    }

    cout << "Thank you for using my To-Do List Application! :)" << endl;

    /* system("Pause");

    currentFile = "test.json";

    manager.fileNameUpdate(mainFileCtrl,currentFile);

    mainFileCtrl.listTasksByPriority();

   // currentFile = "test2.json";
   // manager.fileNameUpdate(mainFileCtrl, currentFile);
   // manager.deleteFile(currentFile);

    manager.print(); */
    return 0;
}
