//
// Created by Owner on 1/1/2025.
//

#ifndef TODO_LIST_APPLICATION_TODOLISTING_H
#define TODO_LIST_APPLICATION_TODOLISTING_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class TaskManager {
private:
    json tasks;
    std::string filename;
public:
    TaskManager(std::string filename);
    ~TaskManager();

    const json &getTasks() const;

    void addTask(const std::string& task, const std::string& priority, const std::string& due_date);
    void listTasksByPriority()const;
    void saveTasks()const;
    void edit(const std::string& oldTask, const std::string& newTask, const std::string& newPriority, const std::string& newDueDate);
    void loadTasks();
    void deleteTaskByName(const std::string& taskName);
    void deleteAllTasks();
    // Create function that clears tasks array when a different file is inputed
    // function that creates file
};

class FileManager{
private:
    std::string managerFile;

public:
    FileManager();
    ~FileManager();

    void print();
// Function that opens .txt file that stores json filenames
// Function to check filename input and make sure its valid then move it to the taskmanager class via getter
// function that deletes whole file and removes it from the .txt file

// create function that handles a non-existing file
/* handle making it so when one files open the rest close off
 * so one instance of the TaskManager class is being run at a time
 *
 * u dont need to have a close file function because the file is closed within different functions***
*/

};

#endif //TODO_LIST_APPLICATION_TODOLISTING_H
