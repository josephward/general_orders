cmake_minimum_required(VERSION 3.22.1)
project(general_orders)

# include_directories("${CMAKE_SOURCE_DIR}/include")
# add_library("${CMAKE_SOURCE_DIR}/include/classes.h")
# set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
#     CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/include/classes.h")
target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/include/name_list.h")