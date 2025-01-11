cmake_minimum_required(VERSION 3.26)
project(ToDo_List_Application)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToDo_List_Application main.cpp
        ToDoListing.cpp
        ToDoListing.h)
