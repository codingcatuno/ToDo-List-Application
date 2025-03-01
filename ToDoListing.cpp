//

#include "ToDoListing.h"

//
// Created by Owner on 1/1/2025.
void logclear(){
    for (int i = 0; i < 50;++i){
        std::cout << std::endl;
    }}

TaskManager::TaskManager(std::string filename) {
    this->filename = filename;
    loadTasks();
    listTasksByPriority();
}


TaskManager::TaskManager() = default;

TaskManager::~TaskManager() = default;

void TaskManager::saveTasks() const {
    std::ofstream outputFile(filename);
    if (!fs::exists(filename)){
        std::cout << "File does not exist!" << std::endl;

    }
    if (outputFile.is_open()){
        outputFile << tasks.dump(4);
        outputFile.close();
    }else{
        std::cerr << "Could not open file " << filename << "\n";
    }
}

void TaskManager::addTask(const std::string &task, const std::string &priority, const std::string &dueDate) {
    json newTask = {{"task", task}, {"priority", priority}, {"due_date", dueDate}};
    tasks.push_back(newTask);
    saveTasks();
    std::cout << "Task has successfully been added!\n";
}

const json &TaskManager::getTasks() const {
    return tasks;
}

void TaskManager::listTasksByPriority() const {
    if(tasks.empty()){
        std::cout << "There are NO tasks left ! :)" << std::endl;
    }
    else {
        for (const auto &task: tasks) {
            if (task["priority"] == "High") {
                std::cout << "Task: " << task["task"] << "\n";
                std::cout << "Due Date: " << task["due_date"] << "\n";
                std::cout << "Priority: " << task["priority"] << "\n\n";
            }
        }
        for (const auto &task: tasks) {
            if (task["priority"] == "Medium") {
                std::cout << "Task: " << task["task"] << "\n";
                std::cout << "Due Date: " << task["due_date"] << "\n";
                std::cout << "Priority: " << task["priority"] << "\n\n";
            }
        }
        for (const auto &task: tasks) {
            if (task["priority"] == "Low") {
                std::cout << "Task: " << task["task"] << "\n";
                std::cout << "Due Date: " << task["due_date"] << "\n";
                std::cout << "Priority: " << task["priority"] << "\n\n";
            }
        }
    }
}

void TaskManager::edit(const std::string& oldTask, const std::string& newTask, const std::string& newPriority, const std::string& newDueDate){
    for (auto& task : tasks){
        if (task["task"] == oldTask){
            task["task"] = newTask;
            task["priority"] = newPriority;
            task["due_date"] = newDueDate;
            saveTasks();
            std::cout << "Task updated successfully! \n";
            return;
        }
    }
    // If task is not found
    std::cout << "Task not found: " << oldTask << "\n";
}

bool TaskManager::checkFoundTask(const std::string& oldTask) {
    for (auto& task : tasks){
        if (task["task"] == oldTask){
            return true;
        }
    }
    // If task is not found
    return false;
}

void TaskManager::loadTasks() {
    std:: ifstream inputFile(filename);
    if (inputFile.is_open()){
        /*if (inputFile.tellg() == 0){
            std::cout << "File has successfuly opened\nNo Tasks to import, Add your tasks!";
            tasks = json::array(); // New array
            return;
        }*/
        try{
            if (!tasks.empty()){
               tasks = json::array(); // Resets tasks to an empty array if tasks are in it
            }
            inputFile >> tasks;
            std::cout << "File has successfully opened!\nTasks loaded successfully from " << filename << "\n";
        } catch (const std::exception& e){
            std::cout << "File has sucessfully opened!\nError loading tasks: " << e.what() << "\n";
            tasks = json::array(); // Reset tasks to an empty array
        }
        inputFile.close();
    } else{
        std::ofstream outputFile(filename);
        if (outputFile.is_open()){
            std::cout << "Could not open file " << filename << ". Starting new file with empty task list. \n";
            tasks = json::array(); // Starts empty task list if file can't be opened
            outputFile.close();
            saveTasks();
        }else{
            std::cout << "Error opening file & creating new file. :/\n";
        }
    }
}

void TaskManager::deleteTaskByName(const std::string& taskName){
    bool taskFound = false;

    for(auto it = tasks.begin(); it != tasks.end(); ++it){
        if((*it)["task"] == taskName){
            tasks.erase(it);
            taskFound = true;
            saveTasks();
            std::cout << "Task '" << taskName << "' deleted successfully. \n";
            break;
        }
    }
    if (!taskFound){
        std::cerr << "Task '" << taskName << "' not found.\n";
    }
}

void TaskManager::deleteAllTasks() {
    std::string confirmation;
    if (tasks.empty()){
        std::cerr << "No tasks to delete :/" << std::endl;
    } else {
        std::cout << "YOU ARE ABOUT TO DELETE ALL YOUR TASKS IN THIS FILE\n"
                  << "Type in \"CONFIRM\" to continue: ";
        std::cin >> confirmation;
        logclear();
        if (confirmation == "CONFIRM"){
            tasks.clear();
            saveTasks();
            std::cout << "All tasks have successfully been deleted!\n";
        } else{
            std::cout << "All tasks deletion has been prevented!\n";
        }
    }
}

void TaskManager::setFilename(const std::string &fn) {
    TaskManager::filename = fn;
    loadTasks();
}

bool TaskManager::checkEmpty() {
    return tasks.empty();
}

// File Manager Class

FileManager::FileManager() {
managerFile = "FileManagerFile.txt";
}

FileManager::~FileManager()= default;

void FileManager::print() {
    std::ifstream ioFile(managerFile);

    std::string line;
    int count = 0;

    if (ioFile.is_open()){
        if (!std::getline(ioFile,line)){
            std::cerr << "\nDirectory is Empty! Please add a NEW file. " << std::endl;
        }
        ioFile.seekg(0,std::ios::beg);
        while(std::getline(ioFile,line)){
            std::cout << ++count << ". ";
            std::cout << line << std:: endl;
        }
        ioFile.close();
    }else{
        std::cout << "Unable to open FileManager Directory :/, If you remember the Task File Name try inputing it." << std::endl;
    }
}

void FileManager::fileNameUpdate(TaskManager& mainFile,std::string& fileName) {
    // 1 check directory to see if file is already there and if not add file name to the FileManagerFile.txt
    // 2 change the filename in the taskmanager class with the setter

    // 1
    if (!checkFileName(fileName)){
        std::ofstream outputFile(managerFile, std::ios::app);
        if (outputFile.is_open()) {
            outputFile << fileName << "\n"; // Append new file to the file
            outputFile.close();
            std::cout << "New file Successfully Added!\n";
        } else{
            std::cerr << "Failed to open file." << std::endl;
        }
    } else {
     std::cout << "Accessing \"" << fileName << "\"..." << std::endl;
    }
    // 2
    mainFile.setFilename(fileName);
}

bool FileManager::checkFileName(std::string &fileName) {
    std::ifstream inputFile(managerFile);
    std::string line;
    const std::string& target = fileName;

    if (inputFile.is_open()){
        while (std::getline(inputFile,line)){ // Read file line by line
            if(line == target){                      // Compare each line with the target
                inputFile.close();
                return true;
            }
        }
    } else{
        std::cerr << "Failed to open the file." << std::endl;
    }
    return false;
}

void FileManager::deleteFile(std::string &fileName) {
    std::string confirmation;
    if (!checkFileName(fileName)){
        std::cerr << "File does NOT exist! :/" << std::endl;
        return;
    }
    std::cout << "YOU ARE ABOUT TO DELETE THIS FILE\n"
                << "Type in \"CONFIRM\" to continue: ";
    std::cin >> confirmation;
    logclear();
    if (confirmation == "CONFIRM"){
        std::cout << "File has successfully been deleted!\n";
    } else{
        std::cout << "File deletion has been prevented!\n";
        return;
    }
    const std::string& target = fileName;
    std::string tempFileName = "temp.txt";

    std::ifstream inputFile(managerFile);
    std::ofstream tempFile(tempFileName);

    if (!inputFile.is_open() || !tempFile.is_open()){
        std::cerr << "Could not open files." << std::endl;
    }

    std::string line;
    while (std::getline(inputFile,line)){
        if(line != target){
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    if (std::remove(managerFile.c_str()) != 0){
        std::cerr << "Error deleting original FileManagerFile.txt" << std::endl;
        return;
    }

    if (std::rename(tempFileName.c_str(), managerFile.c_str()) != 0){
        std::cerr << "Error renaming temp to original" << std::endl;
        return;
    }

    if (std::remove(fileName.c_str()) == 0){
        std::cout << "File successfully deleted." << std::endl;
    } else {
        std::cerr << "Error: File could not be deleted." << std::endl;
    }
}
