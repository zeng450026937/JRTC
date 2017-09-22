cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "3rdParty")

project(${PROJECT_NAME})

message(STATUS "Configuring ${PROJECT_NAME}")

add_subdirectory(LibIDN)
add_subdirectory(ZLib)
add_subdirectory(Boost)