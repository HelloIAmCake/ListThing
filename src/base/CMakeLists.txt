cmake_minimum_required(VERSION 3.0)
project(base)

file(GLOB SOURCES "*.cpp")

add_library(listbase ${SOURCES})
target_include_directories(listbase PUBLIC .)