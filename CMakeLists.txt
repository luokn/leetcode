cmake_minimum_required(VERSION 3.12)

project(leetcode)
set(CMAKE_CXX_STANDARD 17)

file(GLOB src_files LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
foreach(file IN LISTS src_files)
    get_filename_component(exec ${file} NAME_WE)
    add_executable(${exec} ${file})
    message("${file} => [${exec}]")
endforeach()