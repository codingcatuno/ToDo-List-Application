//
// Created by Owner on 1/1/2025.
//

#ifndef TODO_LIST_APPLICATION_TODOLISTING_H
#define TODO_LIST_APPLICATION_TODOLISTING_H

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
#include "json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

class TaskManager {
private:
    json tasks;
    std::string filename;
public:
    void setFilename(const std::string &filename);

public:
    TaskManager(std::string filename);
    TaskManager();
    ~TaskManager();

    const json &getTasks() const;

    void addTask(const std::string& task, const std::string& priority, const std::string& due_date);
    void listTasksByPriority()const;
    void saveTasks()const;
    void edit(const std::string& oldTask, const std::string& newTask, const std::string& newPriority, const std::string& newDueDate);
    void loadTasks();
    void deleteTaskByName(const std::string& taskName);
    void deleteAllTasks();
    // function that creates file
};

class FileManager{
private:
    std::string managerFile;

public:
    FileManager();
    ~FileManager();

    void print();
    void fileNameUpdate(TaskManager& mainFile,std::string& fileName); //work on I couldnt figure this out at the time but there are two test json files
    bool checkFileName(std::string& fileName);
    void deleteFile(std::string& fileName);  // Make it so that it also deletes the line in the directory file

// Function to check filename input and make sure its valid then move it to the taskmanager class via setter

// create function that handles a non-existing file
/* handle making it so when one files open the rest close off
 * so one instance of the TaskManager class is being run at a time
 *
 * u dont need to have a close file function because the file is closed within different functions***
*/

};

void logclear();

#endif //TODO_LIST_APPLICATION_TODOLISTING_H
