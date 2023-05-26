cmake_minimum_required(VERSION 3.6.0)
project(general_orders)

include_directories("include")
add_executable(${PROJECT_NAME}  src/main.cpp 
                                src/Soldier.cpp 
                                src/Company.cpp
                                src/Platoon.cpp
                                src/name_list.cpp)
