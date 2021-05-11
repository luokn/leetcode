cmake_minimum_required(VERSION 3.12)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

file(GLOB main_files LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
foreach(main_file IN LISTS main_files)
    get_filename_component(main_name ${main_file} NAME_WE)
    add_executable(${main_name} ${main_file})
endforeach()