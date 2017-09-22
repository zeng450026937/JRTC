cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "JXMPP")

project(${PROJECT_NAME})

message(STATUS "Configuring ${PROJECT_NAME}")

include_directories(
    .
    ..
)

file(GLOB SOURCE
    Base/*.cpp
    JID/*.cpp
)
file(GLOB HEADER
    Base/*.h
    JID/*.h
)

add_definitions(-D${PROJECT_NAME}_EXPORTS)

if(STATIC)
    add_definitions(-D${PROJECT_NAME}_STATIC)
endif()

add_library(${PROJECT_NAME} ${SOURCE} $<TARGET_OBJECTS:LibIDN> $<TARGET_OBJECTS:ZLib>)