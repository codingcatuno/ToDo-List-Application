//

#include "ToDoListing.h"

//
// Created by Owner on 1/1/2025.
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
    if (tasks.empty()){
        std::cerr << "No tasks to delete :/" << std::endl;
    } else {
        tasks.clear();
        saveTasks();
        std::cout << "All tasks have successfully been deleted!\n";
    }
}

void TaskManager::setFilename(const std::string &filename) {
    TaskManager::filename = filename;
    loadTasks();
}

// File Manager Class

FileManager::FileManager() {
managerFile = "FileManagerFile.txt";
}

FileManager::~FileManager()= default;

std::string FileManager::fileNameUpdate(std::string &fileName) {

    return std::string();
}

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
