cmake_minimum_required(VERSION 3.12)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

message( ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB main_files LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(main_file IN LISTS main_files)
    cmake_path(GET main_file STEM main_name)
    add_executable(${main_name} ${main_file})
endforeach()